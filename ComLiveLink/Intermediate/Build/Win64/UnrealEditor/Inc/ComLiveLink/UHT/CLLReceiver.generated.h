// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "LiveLink/CLLReceiver.h"
#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef COMLIVELINK_CLLReceiver_generated_h
#error "CLLReceiver.generated.h already included, missing '#pragma once' in CLLReceiver.h"
#endif
#define COMLIVELINK_CLLReceiver_generated_h

#define FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Public_LiveLink_CLLReceiver_h_64_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCLLReceiver(); \
	friend struct Z_Construct_UClass_UCLLReceiver_Statics; \
public: \
	DECLARE_CLASS(UCLLReceiver, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ComLiveLink"), COMLIVELINK_API) \
	DECLARE_SERIALIZER(UCLLReceiver)


#define FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Public_LiveLink_CLLReceiver_h_64_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	COMLIVELINK_API UCLLReceiver(); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	UCLLReceiver(UCLLReceiver&&); \
	UCLLReceiver(const UCLLReceiver&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(COMLIVELINK_API, UCLLReceiver); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCLLReceiver); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCLLReceiver) \
	COMLIVELINK_API virtual ~UCLLReceiver();


#define FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Public_LiveLink_CLLReceiver_h_61_PROLOG
#define FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Public_LiveLink_CLLReceiver_h_64_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Public_LiveLink_CLLReceiver_h_64_INCLASS_NO_PURE_DECLS \
	FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Public_LiveLink_CLLReceiver_h_64_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> COMLIVELINK_API UClass* StaticClass<class UCLLReceiver>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_PluginBuild54_Plugins_ComLiveLink_ComLiveLink_Source_ComLiveLink_Public_LiveLink_CLLReceiver_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
