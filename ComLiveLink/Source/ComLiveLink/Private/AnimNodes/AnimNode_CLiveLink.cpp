// Copyright com04. All Rights Reserved.

#include "AnimNodes/AnimNode_CLiveLink.h"

#include "LiveLink/CLLReceiver.h"

#include "Animation/AnimInstanceProxy.h"
#include "Animation/AnimStats.h"


#include UE_INLINE_GENERATED_CPP_BY_NAME(AnimNode_CLiveLink)


FAnimNode_CLiveLink::FAnimNode_CLiveLink()
: Super()
{
}

bool FAnimNode_CLiveLink::HasPreUpdate() const
{
	return true;
}
void FAnimNode_CLiveLink::PreUpdate(const UAnimInstance* InAnimInstance)
{
	Super::PreUpdate(InAnimInstance);
	
	UCLLReceiver* Receiver = UCLLReceiver::Get(InAnimInstance);
	if (Receiver)
	{
		Receiver->Start();
		
		const TSharedPtr<FCLLPacketData>* SharedPacketData = Receiver->GetPacketData(SubjectName);
		if (!SharedPacketData)
		{
			return;
		}
		const FCLLPacketData* PacketData = (*SharedPacketData).Get();
		switch (PacketData->ControlType)
		{
		case ECLLControlType::Pose:
			{
				const FCLLPosePacketData* PosePacket = reinterpret_cast<const FCLLPosePacketData*>(PacketData);
				BoneTransforms = PosePacket->Transforms;
			}
			break;
		}
	}
	else
	{
	}
}

void FAnimNode_CLiveLink::GatherDebugData(FNodeDebugData& DebugData)
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_ANIMNODE(GatherDebugData)
	FString DebugLine = DebugData.GetNodeName(this);
	DebugData.AddDebugItem(DebugLine);
}

bool FAnimNode_CLiveLink::IsValidToEvaluate(const USkeleton* Skeleton, const FBoneContainer& RequiredBones)
{
	return true;
}


void FAnimNode_CLiveLink::EvaluateSkeletalControl_AnyThread(FComponentSpacePoseContext& Output, TArray<FBoneTransform>& OutBoneTransforms)
{
	DECLARE_SCOPE_HIERARCHICAL_COUNTER_ANIMNODE(EvaluateSkeletalControl_AnyThread)
	ANIM_MT_SCOPE_CYCLE_COUNTER_VERBOSE(CLiveLink, !IsInGameThread());


	if (BoneTransforms.IsSet())
	{
		const float BlendWeight = FMath::Clamp<float>(ActualAlpha, 0.f, 1.f);

		const FBoneContainer& BoneContainer = Output.Pose.GetPose().GetBoneContainer();
		const FTransform ComponentTransform = Output.AnimInstanceProxy->GetComponentTransform();
		for (const auto& BoneTransform : BoneTransforms.GetValue())
		{
			const int32 PoseBoneIndex = BoneContainer.GetPoseBoneIndexForBoneName(BoneTransform.Key);
			const FCompactPoseBoneIndex CompactPoseBoneIndex = BoneContainer.MakeCompactPoseIndex(FMeshPoseBoneIndex(PoseBoneIndex));
			
			FTransform Transform = Output.Pose.GetComponentSpaceTransform(CompactPoseBoneIndex);
			FAnimationRuntime::ConvertCSTransformToBoneSpace(ComponentTransform, Output.Pose, Transform, CompactPoseBoneIndex, EBoneControlSpace::BCS_BoneSpace);

			const FTransform& LinkTransform = BoneTransform.Value;
			Transform.SetScale3D(LinkTransform.GetScale3D() * Transform.GetScale3D());
			Transform.SetRotation(LinkTransform.GetRotation() * Transform.GetRotation());
			Transform.AddToTranslation(LinkTransform.GetTranslation());
			FAnimationRuntime::ConvertBoneSpaceTransformToCS(ComponentTransform, Output.Pose, Transform, CompactPoseBoneIndex, EBoneControlSpace::BCS_BoneSpace);

			// モーションした結果を利用するので即時反映させる
			TArray<FBoneTransform> TransformArray = { FBoneTransform(CompactPoseBoneIndex, Transform) };
			Output.Pose.LocalBlendCSBoneTransforms(TransformArray, BlendWeight);
		}
	}
}

void FAnimNode_CLiveLink::CopyNodeData(const FAnimNode_CLiveLink& InCopyFrom)
{
	BoneTransforms = InCopyFrom.BoneTransforms;
}
