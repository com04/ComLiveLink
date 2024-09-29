// Copyright com04. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "Common/UdpSocketReceiver.h"
#include "Subsystems/GameInstanceSubsystem.h"

#include "CLLReceiver.generated.h"


/**
 * 操作種類
 */
enum class ECLLControlType
{
	/// 無し
	None,
	/// ポーズ
	Pose,

	// TODO: 外部からDelegateで追加出来るようにする
	ExternalStart = 100,
};

/**
 * ボーン一つのTransform情報 <BoneName, Transform>
 */
using FCLLBoneTransforms = TMap<FName, FTransform>;

/**
 * 1フレーム分のアニメーションセット <Time, BoneTransform>
 */
using FCLLAnimationData = TMap<float, FCLLBoneTransforms>;

/**
 * パケット情報
 */
struct FCLLPacketData
{
	ECLLControlType ControlType = ECLLControlType::None;

	/// True: ボーン個別で送信される。前回バッファから蓄積する False: ボーンをすべて一斉に送信している
	bool bAccumulate = false;

	virtual ~FCLLPacketData(){}
	virtual void MergeAccumulate(const FCLLPacketData& OldPacketData) = 0;
};

/**
 * パケット：ポーズ情報
 */
struct FCLLPosePacketData : public FCLLPacketData
{
	FCLLBoneTransforms Transforms;

	virtual void MergeAccumulate(const FCLLPacketData& OldPacketData) override;
};






/**
 * LiveLink 用のパケット受信、保持クラス
 */
UCLASS(MinimalAPI)
class UCLLReceiver : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	static UCLLReceiver* Get(const UObject* InWorldContextObject);

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	/// 受信開始。すでに開始済みなら何もしない
	void Start();

	/// 受信したパケットを取得
	const TSharedPtr<FCLLPacketData>* GetPacketData(const FName& InSubjectName) const;

private:
	/// パケット受信コールバック
	void OnPacketReceived(const FArrayReaderPtr& InData, const struct FIPv4Endpoint& InEndpoint);

	/// ECLLControlType::Pose のパケット受信
	TSharedPtr<FCLLPacketData> ReceivePosePakcet(const TSharedPtr<FJsonObject>& InJsonParams);
private:
	/// 通信ソケット
	class FSocket* Socket = nullptr;

	/// 受信用クラス
	TUniquePtr<class FUdpSocketReceiver> SocketReceiver;

	/// 受信結果。<SubjectName, Packet>
	TMap<FName, TSharedPtr<FCLLPacketData>> PacketData;
};
