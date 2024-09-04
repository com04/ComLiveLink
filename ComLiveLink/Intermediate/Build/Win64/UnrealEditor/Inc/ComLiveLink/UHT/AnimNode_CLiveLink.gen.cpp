// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ComLiveLink/Public/AnimNodes/AnimNode_CLiveLink.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAnimNode_CLiveLink() {}

// Begin Cross Module References
ANIMGRAPHRUNTIME_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_SkeletalControlBase();
COMLIVELINK_API UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_CLiveLink();
UPackage* Z_Construct_UPackage__Script_ComLiveLink();
// End Cross Module References

// Begin ScriptStruct FAnimNode_CLiveLink
static_assert(std::is_polymorphic<FAnimNode_CLiveLink>() == std::is_polymorphic<FAnimNode_SkeletalControlBase>(), "USTRUCT FAnimNode_CLiveLink cannot be polymorphic unless super FAnimNode_SkeletalControlBase is polymorphic");
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_AnimNode_CLiveLink;
class UScriptStruct* FAnimNode_CLiveLink::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_AnimNode_CLiveLink.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_AnimNode_CLiveLink.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FAnimNode_CLiveLink, (UObject*)Z_Construct_UPackage__Script_ComLiveLink(), TEXT("AnimNode_CLiveLink"));
	}
	return Z_Registration_Info_UScriptStruct_AnimNode_CLiveLink.OuterSingleton;
}
template<> COMLIVELINK_API UScriptStruct* StaticStruct<FAnimNode_CLiveLink>()
{
	return FAnimNode_CLiveLink::StaticStruct();
}
struct Z_Construct_UScriptStruct_FAnimNode_CLiveLink_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintInternalUseOnly", "true" },
		{ "BlueprintType", "true" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "// This represents a baked transition\n" },
#endif
		{ "ModuleRelativePath", "Public/AnimNodes/AnimNode_CLiveLink.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "This represents a baked transition" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SubjectName_MetaData[] = {
		{ "Category", "SourceData" },
		{ "ModuleRelativePath", "Public/AnimNodes/AnimNode_CLiveLink.h" },
		{ "PinShownByDefault", "" },
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FNamePropertyParams NewProp_SubjectName;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAnimNode_CLiveLink>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
};
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FAnimNode_CLiveLink_Statics::NewProp_SubjectName = { "SubjectName", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FAnimNode_CLiveLink, SubjectName), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SubjectName_MetaData), NewProp_SubjectName_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAnimNode_CLiveLink_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAnimNode_CLiveLink_Statics::NewProp_SubjectName,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_CLiveLink_Statics::PropPointers) < 2048);
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAnimNode_CLiveLink_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ComLiveLink,
	Z_Construct_UScriptStruct_FAnimNode_SkeletalControlBase,
	&NewStructOps,
	"AnimNode_CLiveLink",
	Z_Construct_UScriptStruct_FAnimNode_CLiveLink_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_CLiveLink_Statics::PropPointers),
	sizeof(FAnimNode_CLiveLink),
	alignof(FAnimNode_CLiveLink),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000201),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAnimNode_CLiveLink_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FAnimNode_CLiveLink_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FAnimNode_CLiveLink()
{
	if (!Z_Registration_Info_UScriptStruct_AnimNode_CLiveLink.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_AnimNode_CLiveLink.InnerSingleton, Z_Construct_UScriptStruct_FAnimNode_CLiveLink_Statics::StructParams);
	}
	return Z_Registration_Info_UScriptStruct_AnimNode_CLiveLink.InnerSingleton;
}
// End ScriptStruct FAnimNode_CLiveLink

// Begin Registration
struct Z_CompiledInDeferFile_FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Public_AnimNodes_AnimNode_CLiveLink_h_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FAnimNode_CLiveLink::StaticStruct, Z_Construct_UScriptStruct_FAnimNode_CLiveLink_Statics::NewStructOps, TEXT("AnimNode_CLiveLink"), &Z_Registration_Info_UScriptStruct_AnimNode_CLiveLink, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FAnimNode_CLiveLink), 2681898635U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Public_AnimNodes_AnimNode_CLiveLink_h_2177375007(TEXT("/Script/ComLiveLink"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Public_AnimNodes_AnimNode_CLiveLink_h_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Public_AnimNodes_AnimNode_CLiveLink_h_Statics::ScriptStructInfo),
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
