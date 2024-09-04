// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ComLiveLink/Public/LiveLink/CLLReceiver.h"
#include "Runtime/Engine/Classes/Engine/GameInstance.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCLLReceiver() {}

// Begin Cross Module References
COMLIVELINK_API UClass* Z_Construct_UClass_UCLLReceiver();
COMLIVELINK_API UClass* Z_Construct_UClass_UCLLReceiver_NoRegister();
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
UPackage* Z_Construct_UPackage__Script_ComLiveLink();
// End Cross Module References

// Begin Class UCLLReceiver
void UCLLReceiver::StaticRegisterNativesUCLLReceiver()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCLLReceiver);
UClass* Z_Construct_UClass_UCLLReceiver_NoRegister()
{
	return UCLLReceiver::StaticClass();
}
struct Z_Construct_UClass_UCLLReceiver_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * LiveLink \xe7\x94\xa8\xe3\x81\xae\xe3\x83\x91\xe3\x82\xb1\xe3\x83\x83\xe3\x83\x88\xe5\x8f\x97\xe4\xbf\xa1\xe3\x80\x81\xe4\xbf\x9d\xe6\x8c\x81\xe3\x82\xaf\xe3\x83\xa9\xe3\x82\xb9\n */" },
#endif
		{ "IncludePath", "LiveLink/CLLReceiver.h" },
		{ "ModuleRelativePath", "Public/LiveLink/CLLReceiver.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "LiveLink \xe7\x94\xa8\xe3\x81\xae\xe3\x83\x91\xe3\x82\xb1\xe3\x83\x83\xe3\x83\x88\xe5\x8f\x97\xe4\xbf\xa1\xe3\x80\x81\xe4\xbf\x9d\xe6\x8c\x81\xe3\x82\xaf\xe3\x83\xa9\xe3\x82\xb9" },
#endif
	};
#endif // WITH_METADATA
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCLLReceiver>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
UObject* (*const Z_Construct_UClass_UCLLReceiver_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_ComLiveLink,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCLLReceiver_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCLLReceiver_Statics::ClassParams = {
	&UCLLReceiver::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x000800A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCLLReceiver_Statics::Class_MetaDataParams), Z_Construct_UClass_UCLLReceiver_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCLLReceiver()
{
	if (!Z_Registration_Info_UClass_UCLLReceiver.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCLLReceiver.OuterSingleton, Z_Construct_UClass_UCLLReceiver_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCLLReceiver.OuterSingleton;
}
template<> COMLIVELINK_API UClass* StaticClass<UCLLReceiver>()
{
	return UCLLReceiver::StaticClass();
}
UCLLReceiver::UCLLReceiver() {}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCLLReceiver);
UCLLReceiver::~UCLLReceiver() {}
// End Class UCLLReceiver

// Begin Registration
struct Z_CompiledInDeferFile_FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Public_LiveLink_CLLReceiver_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCLLReceiver, UCLLReceiver::StaticClass, TEXT("UCLLReceiver"), &Z_Registration_Info_UClass_UCLLReceiver, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCLLReceiver), 3374975238U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Public_LiveLink_CLLReceiver_h_3439160933(TEXT("/Script/ComLiveLink"),
	Z_CompiledInDeferFile_FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Public_LiveLink_CLLReceiver_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Public_LiveLink_CLLReceiver_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
