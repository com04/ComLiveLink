// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ComLiveLinkEd/Public/AnimGraph/AnimGraphNode_CLiveLink.h"
#include "ComLiveLink/Public/AnimNodes/AnimNode_CLiveLink.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimGraphNode_CLiveLink() {}

// Begin Cross Module References
ANIMGRAPH_API UClass* Z_Construct_UClass_UAnimGraphNode_SkeletalControlBase();
COMLIVELINK_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_CLiveLink();
COMLIVELINKED_API UClass* Z_Construct_UClass_UAnimGraphNode_CLiveLink();
COMLIVELINKED_API UClass* Z_Construct_UClass_UAnimGraphNode_CLiveLink_NoRegister();
UPackage* Z_Construct_UPackage__Script_ComLiveLinkEd();
// End Cross Module References

// Begin Class UAnimGraphNode_CLiveLink
void UAnimGraphNode_CLiveLink::StaticRegisterNativesUAnimGraphNode_CLiveLink()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UAnimGraphNode_CLiveLink);
UClass* Z_Construct_UClass_UAnimGraphNode_CLiveLink_NoRegister()
{
	return UAnimGraphNode_CLiveLink::StaticClass();
}
struct Z_Construct_UClass_UAnimGraphNode_CLiveLink_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "AnimGraph/AnimGraphNode_CLiveLink.h" },
		{ "ModuleRelativePath", "Public/AnimGraph/AnimGraphNode_CLiveLink.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Node_MetaData[] = {
		{ "Category", "Settings" },
		{ "ModuleRelativePath", "Public/AnimGraph/AnimGraphNode_CLiveLink.h" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStructPropertyParams NewProp_Node;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UAnimGraphNode_CLiveLink>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UAnimGraphNode_CLiveLink_Statics::NewProp_Node = { "Node", nullptr, (EPropertyFlags)0x0010000000000001, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UAnimGraphNode_CLiveLink, Node), Z_Construct_UScriptStruct_FAnimNode_CLiveLink, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Node_MetaData), NewProp_Node_MetaData) }; // 2681898635
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UAnimGraphNode_CLiveLink_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UAnimGraphNode_CLiveLink_Statics::NewProp_Node,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_CLiveLink_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UAnimGraphNode_CLiveLink_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UAnimGraphNode_SkeletalControlBase,
	(UObject* (*)())Z_Construct_UPackage__Script_ComLiveLinkEd,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_CLiveLink_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UAnimGraphNode_CLiveLink_Statics::ClassParams = {
	&UAnimGraphNode_CLiveLink::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UAnimGraphNode_CLiveLink_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_CLiveLink_Statics::PropPointers),
	0,
	0x008800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UAnimGraphNode_CLiveLink_Statics::Class_MetaDataParams), Z_Construct_UClass_UAnimGraphNode_CLiveLink_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UAnimGraphNode_CLiveLink()
{
	if (!Z_Registration_Info_UClass_UAnimGraphNode_CLiveLink.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UAnimGraphNode_CLiveLink.OuterSingleton, Z_Construct_UClass_UAnimGraphNode_CLiveLink_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UAnimGraphNode_CLiveLink.OuterSingleton;
}
template<> COMLIVELINKED_API UClass* StaticClass<UAnimGraphNode_CLiveLink>()
{
	return UAnimGraphNode_CLiveLink::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UAnimGraphNode_CLiveLink);
UAnimGraphNode_CLiveLink::~UAnimGraphNode_CLiveLink() {}
// End Class UAnimGraphNode_CLiveLink

// Begin Registration
struct Z_CompiledInDeferFile_FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLinkEd_Public_AnimGraph_AnimGraphNode_CLiveLink_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UAnimGraphNode_CLiveLink, UAnimGraphNode_CLiveLink::StaticClass, TEXT("UAnimGraphNode_CLiveLink"), &Z_Registration_Info_UClass_UAnimGraphNode_CLiveLink, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UAnimGraphNode_CLiveLink), 2412849682U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLinkEd_Public_AnimGraph_AnimGraphNode_CLiveLink_h_3109329856(TEXT("/Script/ComLiveLinkEd"),
	Z_CompiledInDeferFile_FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLinkEd_Public_AnimGraph_AnimGraphNode_CLiveLink_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLinkEd_Public_AnimGraph_AnimGraphNode_CLiveLink_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
