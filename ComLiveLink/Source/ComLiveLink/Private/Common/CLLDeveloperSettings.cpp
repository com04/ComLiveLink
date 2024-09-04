// Copyright com04 All Rights Reserved.

#include "Common/CLLDeveloperSettings.h"


#define LOCTEXT_NAMESPACE "CLLDeveloperSettings"


UCLLDeveloperSettings::UCLLDeveloperSettings()
: Super()
{
}
UCLLDeveloperSettings::~UCLLDeveloperSettings()
{
}

/** return "Project" or "Editor" */
FName UCLLDeveloperSettings::GetContainerName() const 
{
	return "Editor";
}

/** 設定画面の大項目のカテゴライズ */
FName UCLLDeveloperSettings::GetCategoryName() const
{
	return "Plugins";
}

const UCLLDeveloperSettings* UCLLDeveloperSettings::Get()
{
	return GetDefault<UCLLDeveloperSettings>();
}
UCLLDeveloperSettings* UCLLDeveloperSettings::GetWritable()
{
	return GetMutableDefault<UCLLDeveloperSettings>();
}

#undef LOCTEXT_NAMESPACE
