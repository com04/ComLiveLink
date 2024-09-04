// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ComLiveLink/Private/Common/CLLDeveloperSettings.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCLLDeveloperSettings() {}

// Begin Cross Module References
COMLIVELINK_API UClass* Z_Construct_UClass_UCLLDeveloperSettings();
COMLIVELINK_API UClass* Z_Construct_UClass_UCLLDeveloperSettings_NoRegister();
DEVELOPERSETTINGS_API UClass* Z_Construct_UClass_UDeveloperSettings();
UPackage* Z_Construct_UPackage__Script_ComLiveLink();
// End Cross Module References

// Begin Class UCLLDeveloperSettings
void UCLLDeveloperSettings::StaticRegisterNativesUCLLDeveloperSettings()
{
}
IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(UCLLDeveloperSettings);
UClass* Z_Construct_UClass_UCLLDeveloperSettings_NoRegister()
{
	return UCLLDeveloperSettings::StaticClass();
}
struct Z_Construct_UClass_UCLLDeveloperSettings_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
#if !UE_BUILD_SHIPPING
		{ "Comment", "/**\n * Editor\xe8\xa8\xad\xe5\xae\x9a\n */" },
#endif
		{ "DisplayName", "Com Live Link Plugin" },
		{ "IncludePath", "Common/CLLDeveloperSettings.h" },
		{ "ModuleRelativePath", "Private/Common/CLLDeveloperSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "Editor\xe8\xa8\xad\xe5\xae\x9a" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_IPAddress_MetaData[] = {
		{ "Category", "Option" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8e\xa5\xe7\xb6\x9a\xe5\x85\x88\xe3\x81\xaeIP\xe3\x82\xa2\xe3\x83\x89\xe3\x83\xac\xe3\x82\xb9 */" },
#endif
		{ "DisplayName", "\xe9\x80\x81\xe4\xbf\xa1\xe5\x85\x83IP\xe3\x82\xa2\xe3\x83\x89\xe3\x83\xac\xe3\x82\xb9" },
		{ "ModuleRelativePath", "Private/Common/CLLDeveloperSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8e\xa5\xe7\xb6\x9a\xe5\x85\x88\xe3\x81\xaeIP\xe3\x82\xa2\xe3\x83\x89\xe3\x83\xac\xe3\x82\xb9" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Port_MetaData[] = {
		{ "Category", "Option" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe6\x8e\xa5\xe7\xb6\x9a\xe3\x81\xab\xe4\xbd\xbf\xe7\x94\xa8\xe3\x81\x99\xe3\x82\x8b\xe3\x83\x9d\xe3\x83\xbc\xe3\x83\x88\xe7\x95\xaa\xe5\x8f\xb7 */" },
#endif
		{ "DisplayName", "\xe3\x83\x9d\xe3\x83\xbc\xe3\x83\x88\xe7\x95\xaa\xe5\x8f\xb7" },
		{ "ModuleRelativePath", "Private/Common/CLLDeveloperSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe6\x8e\xa5\xe7\xb6\x9a\xe3\x81\xab\xe4\xbd\xbf\xe7\x94\xa8\xe3\x81\x99\xe3\x82\x8b\xe3\x83\x9d\xe3\x83\xbc\xe3\x83\x88\xe7\x95\xaa\xe5\x8f\xb7" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReceiveBufferSize_MetaData[] = {
		{ "Category", "Option" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x8f\x97\xe4\xbf\xa1\xe3\x83\x90\xe3\x83\x83\xe3\x83\x95\xe3\x82\xa1\xe3\x82\xb5\xe3\x82\xa4\xe3\x82\xba */" },
#endif
		{ "DisplayName", "\xe5\x8f\x97\xe4\xbf\xa1\xe3\x83\x90\xe3\x83\x83\xe3\x83\x95\xe3\x82\xa1\xe3\x82\xb5\xe3\x82\xa4\xe3\x82\xba" },
		{ "ModuleRelativePath", "Private/Common/CLLDeveloperSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x8f\x97\xe4\xbf\xa1\xe3\x83\x90\xe3\x83\x83\xe3\x83\x95\xe3\x82\xa1\xe3\x82\xb5\xe3\x82\xa4\xe3\x82\xba" },
#endif
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReceiveThreadTime_MetaData[] = {
		{ "Category", "Option" },
#if !UE_BUILD_SHIPPING
		{ "Comment", "/** \xe5\x8f\x97\xe4\xbf\xa1\xe5\x87\xa6\xe7\x90\x86\xe3\x82\xb9\xe3\x83\xac\xe3\x83\x83\xe3\x83\x89\xe3\x81\xae\xe9\x96\x93\xe9\x9a\x94 */" },
#endif
		{ "DisplayName", "\xe5\x8f\x97\xe4\xbf\xa1\xe9\x96\x93\xe9\x9a\x94[ms]" },
		{ "ModuleRelativePath", "Private/Common/CLLDeveloperSettings.h" },
#if !UE_BUILD_SHIPPING
		{ "ToolTip", "\xe5\x8f\x97\xe4\xbf\xa1\xe5\x87\xa6\xe7\x90\x86\xe3\x82\xb9\xe3\x83\xac\xe3\x83\x83\xe3\x83\x89\xe3\x81\xae\xe9\x96\x93\xe9\x9a\x94" },
#endif
	};
#endif // WITH_METADATA
	static const UECodeGen_Private::FStrPropertyParams NewProp_IPAddress;
	static const UECodeGen_Private::FStrPropertyParams NewProp_Port;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReceiveBufferSize;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReceiveThreadTime;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCLLDeveloperSettings>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
};
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UCLLDeveloperSettings_Statics::NewProp_IPAddress = { "IPAddress", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCLLDeveloperSettings, IPAddress), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_IPAddress_MetaData), NewProp_IPAddress_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UClass_UCLLDeveloperSettings_Statics::NewProp_Port = { "Port", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCLLDeveloperSettings, Port), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Port_MetaData), NewProp_Port_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCLLDeveloperSettings_Statics::NewProp_ReceiveBufferSize = { "ReceiveBufferSize", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCLLDeveloperSettings, ReceiveBufferSize), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReceiveBufferSize_MetaData), NewProp_ReceiveBufferSize_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UClass_UCLLDeveloperSettings_Statics::NewProp_ReceiveThreadTime = { "ReceiveThreadTime", nullptr, (EPropertyFlags)0x0010000000004001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCLLDeveloperSettings, ReceiveThreadTime), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReceiveThreadTime_MetaData), NewProp_ReceiveThreadTime_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCLLDeveloperSettings_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCLLDeveloperSettings_Statics::NewProp_IPAddress,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCLLDeveloperSettings_Statics::NewProp_Port,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCLLDeveloperSettings_Statics::NewProp_ReceiveBufferSize,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCLLDeveloperSettings_Statics::NewProp_ReceiveThreadTime,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCLLDeveloperSettings_Statics::PropPointers) < 2048);
UObject* (*const Z_Construct_UClass_UCLLDeveloperSettings_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDeveloperSettings,
	(UObject* (*)())Z_Construct_UPackage__Script_ComLiveLink,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCLLDeveloperSettings_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCLLDeveloperSettings_Statics::ClassParams = {
	&UCLLDeveloperSettings::StaticClass,
	"EditorPerProjectUserSettings",
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCLLDeveloperSettings_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCLLDeveloperSettings_Statics::PropPointers),
	0,
	0x000000A4u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCLLDeveloperSettings_Statics::Class_MetaDataParams), Z_Construct_UClass_UCLLDeveloperSettings_Statics::Class_MetaDataParams)
};
UClass* Z_Construct_UClass_UCLLDeveloperSettings()
{
	if (!Z_Registration_Info_UClass_UCLLDeveloperSettings.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCLLDeveloperSettings.OuterSingleton, Z_Construct_UClass_UCLLDeveloperSettings_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCLLDeveloperSettings.OuterSingleton;
}
template<> COMLIVELINK_API UClass* StaticClass<UCLLDeveloperSettings>()
{
	return UCLLDeveloperSettings::StaticClass();
}
DEFINE_VTABLE_PTR_HELPER_CTOR(UCLLDeveloperSettings);
// End Class UCLLDeveloperSettings

// Begin Registration
struct Z_CompiledInDeferFile_FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Private_Common_CLLDeveloperSettings_h_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCLLDeveloperSettings, UCLLDeveloperSettings::StaticClass, TEXT("UCLLDeveloperSettings"), &Z_Registration_Info_UClass_UCLLDeveloperSettings, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCLLDeveloperSettings), 2354008112U) },
	};
};
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Private_Common_CLLDeveloperSettings_h_3806477811(TEXT("/Script/ComLiveLink"),
	Z_CompiledInDeferFile_FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Private_Common_CLLDeveloperSettings_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Private_Common_CLLDeveloperSettings_h_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0);
// End Registration
PRAGMA_ENABLE_DEPRECATION_WARNINGS
