// Copyright com04 All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "CLLDeveloperSettings.generated.h"


/**
 * Editor設定
 */
UCLASS(config = EditorPerProjectUserSettings, meta = (DisplayName = "Com Live Link Plugin"))
class UCLLDeveloperSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	UCLLDeveloperSettings();
	~UCLLDeveloperSettings();

	/** 接続先のIPアドレス */
	UPROPERTY(config, EditAnywhere, Category = "Option", meta = (DisplayName = "送信元IPアドレス"))
	FString IPAddress = TEXT("127.0.0.1");

	/** 接続に使用するポート番号 */
	UPROPERTY(config, EditAnywhere, Category = "Option", meta = (DisplayName = "ポート番号"))
	FString Port = TEXT("2000");

	/** 受信バッファサイズ */
	UPROPERTY(config, EditAnywhere, Category = "Option", meta = (DisplayName = "受信バッファサイズ"))
	int32 ReceiveBufferSize = 16 * 1024 * 1024;

	/** 受信処理スレッドの間隔 */
	UPROPERTY(config, EditAnywhere, Category = "Option", meta = (DisplayName = "受信間隔[ms]"))
	int32 ReceiveThreadTime = 100;



	/** return "Project" or "Editor" */
	virtual FName GetContainerName() const override;

	/** 設定画面の大項目のカテゴライズ */
	virtual FName GetCategoryName() const override;

public:
	static const UCLLDeveloperSettings* Get();
	static UCLLDeveloperSettings* GetWritable();
};