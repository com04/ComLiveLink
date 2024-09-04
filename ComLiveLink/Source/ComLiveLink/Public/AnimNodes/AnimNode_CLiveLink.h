// Copyright com04. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "LiveLink/CLLReceiver.h"

#include "Animation/AnimNodeBase.h"
#include "BoneControllers/AnimNode_SkeletalControlBase.h"
#include "AnimNode_CLiveLink.generated.h"

// This represents a baked transition
USTRUCT(BlueprintInternalUseOnly)
struct COMLIVELINK_API FAnimNode_CLiveLink : public FAnimNode_SkeletalControlBase
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = SourceData, meta = (PinShownByDefault))
	FName SubjectName;

public:
	FAnimNode_CLiveLink();

	// FAnimNode_Base interface
	virtual bool HasPreUpdate() const override;
	virtual void PreUpdate(const UAnimInstance* InAnimInstance) override;
	virtual void GatherDebugData(FNodeDebugData& DebugData) override;
	// End of FAnimNode_Base interface

	// FAnimNode_SkeletalControlBase interface
	virtual bool IsValidToEvaluate(const USkeleton* Skeleton, const FBoneContainer& RequiredBones) override;
	virtual void EvaluateSkeletalControl_AnyThread(FComponentSpacePoseContext& Output, TArray<FBoneTransform>& OutBoneTransforms) override;
	// End of FAnimNode_SkeletalControlBase interface

	void CopyNodeData(const FAnimNode_CLiveLink& InCopyFrom);
private:
	TOptional<FCLLBoneTransforms> BoneTransforms;
};

