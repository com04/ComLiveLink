// Copyright com04. All Rights Reserved.

#include "LiveLink/CLLReceiver.h"

#include "Common/CLLDeveloperSettings.h"

#include "Async/Async.h"
#include "Common/UdpSocketBuilder.h"
#include "Dom/JsonValue.h"
#include "Dom/JsonObject.h"
#include "Engine/GameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Serialization/JsonReader.h"
#include "Sockets.h"



UCLLReceiver* UCLLReceiver::Get(const UObject* InWorldContextObject)
{
	UGameInstance* GameInstance = UGameplayStatics::GetGameInstance(InWorldContextObject);
	if (!GameInstance)
	{
		return nullptr;
	}

	return GameInstance->GetSubsystem<UCLLReceiver>();
}

void UCLLReceiver::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
}

void UCLLReceiver::Deinitialize()
{
	Super::Deinitialize();

	SocketReceiver.Reset();
	if (Socket)
	{
		Socket->Close();
		ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->DestroySocket(Socket);
		Socket = nullptr;
	}
}

void UCLLReceiver::Start()
{
	if (Socket)
	{
		return;
	}
	const UCLLDeveloperSettings* CLLSettings = UCLLDeveloperSettings::Get();
	if (!CLLSettings)
	{
		ensure(false);
		return;
	}

	const FString IPAddress(FString::Printf(TEXT("%s:%s"), *CLLSettings->IPAddress, *CLLSettings->Port));
	FIPv4Endpoint EndPoint;
	if (!FIPv4Endpoint::Parse(IPAddress, EndPoint))
	{
		UE_LOG(LogTemp, Error, TEXT("UCLLReceiver: Invalid ReceiveIPAddress '%s'."), *IPAddress);
		return;
	}

	Socket = FUdpSocketBuilder(TEXT("ComLiveLinkReceiver"))
		.AsNonBlocking()
		.AsReusable()
		.BoundToAddress(EndPoint.Address)
		.BoundToPort(EndPoint.Port)
		.WithReceiveBufferSize(CLLSettings->ReceiveBufferSize);
	if (Socket)
	{
		const FString ReceiverThreadName = TEXT("ComLiveLinkReceiverThread");
		SocketReceiver = MakeUnique<FUdpSocketReceiver>(Socket, FTimespan::FromMilliseconds(CLLSettings->ReceiveThreadTime), *ReceiverThreadName);
		SocketReceiver->OnDataReceived().BindUObject(this, &UCLLReceiver::OnPacketReceived);
		SocketReceiver->Start();
	}
}

const TSharedPtr<FCLLPacketData>* UCLLReceiver::GetPacketData(const FName& InSubjectName) const
{
	return PacketData.Find(InSubjectName);
}

void UCLLReceiver::OnPacketReceived(const FArrayReaderPtr& InData, const FIPv4Endpoint& InEndpoint)
{
	// in runnable thread

	TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(FString(InData->Num(), reinterpret_cast<UTF8CHAR*>(InData->GetData())));

	TSharedPtr<FJsonObject> JsonObject;
	if (!FJsonSerializer::Deserialize(Reader, JsonObject))
	{
		return;
	}
	// 固定タグチェック
	const FString HeaderTag = TEXT("CLL");
	const FString Header = JsonObject->GetStringField(TEXT("header"));
	if (Header != HeaderTag)
	{
		return;
	}
	const FString SubjectName = JsonObject->GetStringField(TEXT("subject"));
	if (SubjectName.IsEmpty())
	{
		return;
	}
	const TSharedPtr<FJsonObject>& Params = JsonObject->GetObjectField(TEXT("params"));
	if (!Params)
	{
		return;
	}

	TSharedPtr<FCLLPacketData> NewPacketData;

	// 各種類に合わせたパケット解析
	const ECLLControlType ControlType = static_cast<ECLLControlType>(JsonObject->GetIntegerField(TEXT("type")));
	switch (ControlType)
	{
	case ECLLControlType::Pose:
		NewPacketData = ReceivePosePakcet(Params);
		break;

	default:
		return;
	}
	if (!NewPacketData)
	{
		return;
	}

	NewPacketData->ControlType = ControlType;

	FName Subject = *SubjectName;
	AsyncTask(ENamedThreads::GameThread, [this, Subject, NewPacketData]()
		{
			PacketData.FindOrAdd(Subject) = NewPacketData;
		});
}

TSharedPtr<FCLLPacketData> UCLLReceiver::ReceivePosePakcet(const TSharedPtr<FJsonObject>& InJsonParams)
{
	TSharedPtr<FCLLPosePacketData> PoseData = MakeShared<FCLLPosePacketData>();
	if (!PoseData)
	{
		return nullptr;
	}

	const TSharedPtr<FJsonObject>& BoneTransforms = InJsonParams->GetObjectField(TEXT("bone_transforms"));
	PoseData->Transforms.Reserve(BoneTransforms->Values.Num());

	for (const auto& BoneTransform : BoneTransforms->Values)
	{
		const TArray<TSharedPtr<FJsonValue>>& TransformArray = BoneTransform.Value->AsArray();
		if (TransformArray.Num() < 4)
		{
			UE_LOG(LogTemp, Warning, TEXT("packet need bone transform greater 4. transform num=%d"), TransformArray.Num());
			continue;
		}
		FQuat Rotation = FQuat(TransformArray[0]->AsNumber(), TransformArray[1]->AsNumber(), TransformArray[2]->AsNumber(), TransformArray[3]->AsNumber());
		Rotation.Normalize();

		FVector Location = FVector::ZeroVector;
		if (TransformArray.Num() >= 7)
		{
			Location = FVector(TransformArray[4]->AsNumber(), TransformArray[5]->AsNumber(), TransformArray[6]->AsNumber());
		}

		FVector Scale = FVector::OneVector;
		if (TransformArray.Num() >= 10)
		{
			Scale = FVector(TransformArray[7]->AsNumber(), TransformArray[8]->AsNumber(), TransformArray[9]->AsNumber());
		}

		FTransform Transform = FTransform(Rotation, Location, Scale);
		PoseData->Transforms.Add(FName(*BoneTransform.Key), Transform);
	}
	return PoseData;
}

