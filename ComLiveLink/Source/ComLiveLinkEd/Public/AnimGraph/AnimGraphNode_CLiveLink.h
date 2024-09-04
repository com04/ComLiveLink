// Copyright com04. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "AnimGraphNode_SkeletalControlBase.h"
#include "AnimNodes/AnimNode_CLiveLink.h"
#include "AnimGraphNode_CLiveLink.generated.h"

UCLASS(MinimalAPI)
class UAnimGraphNode_CLiveLink : public UAnimGraphNode_SkeletalControlBase
{
	GENERATED_UCLASS_BODY()

public:
	// UAnimGraphNode_Base interface
	virtual void CopyNodeDataToPreviewNode(FAnimNode_Base* InPreviewNode) override;
	virtual void CopyPinDefaultsToNodeData(UEdGraphPin* InPin) override;
	// End of UAnimGraphNode_Base interface
	
	// UAnimGraphNode_SkeletalControlBase interface
	virtual const FAnimNode_SkeletalControlBase* GetNode() const override { return &Node; }
	// End of UAnimGraphNode_SkeletalControlBase interface

public:
	UPROPERTY(EditAnywhere, Category=Settings)
	FAnimNode_CLiveLink Node;

protected:
	//~ Begin UEdGraphNode Interface.
	virtual FText GetMenuCategory() const override;
	virtual FText GetTooltipText() const override;
	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;
	//~ End UEdGraphNode Interface.

};
