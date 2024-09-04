// Copyright com04. All Rights Reserved.

#include "AnimGraph/AnimGraphNode_CLiveLink.h"
#include "DetailLayoutBuilder.h"
#include "ScopedTransaction.h"
#include "Kismet2/BlueprintEditorUtils.h"


#define LOCTEXT_NAMESPACE "AnimGraphNode_CLiveLink"

UAnimGraphNode_CLiveLink::UAnimGraphNode_CLiveLink(const FObjectInitializer& ObjectInitializer)
 : Super(ObjectInitializer)
{
}

void UAnimGraphNode_CLiveLink::CopyNodeDataToPreviewNode(FAnimNode_Base* InPreviewNode)
{
	FAnimNode_CLiveLink* ModifyBone = static_cast<FAnimNode_CLiveLink*>(InPreviewNode);
	ModifyBone->CopyNodeData(Node);
}
void UAnimGraphNode_CLiveLink::CopyPinDefaultsToNodeData(UEdGraphPin* InPin)
{
	if (InPin->GetName() == GET_MEMBER_NAME_STRING_CHECKED(FAnimNode_CLiveLink, SubjectName))
	{
//		GetDefaultValue(GET_MEMBER_NAME_STRING_CHECKED(FAnimNode_CLiveLink, SubjectName), Node.SubjectName);
	}
}

FText UAnimGraphNode_CLiveLink::GetMenuCategory() const
{
	return LOCTEXT("ComLiveLinkCategory", "Animation|LiveLink");
}

FText UAnimGraphNode_CLiveLink::GetTooltipText() const
{
	return LOCTEXT("ComLiveLinkTooltip", "Com Live Link");
}

FText UAnimGraphNode_CLiveLink::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return LOCTEXT("ComLiveLinkNodeTitle", "CLiveLink");
}


#undef LOCTEXT_NAMESPACE

