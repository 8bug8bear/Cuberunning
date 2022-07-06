// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CRSaveGame.h"
#include "Engine/GameInstance.h"
#include "CRGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class CUBERUNNING_API UCRGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, Category="SaveGame")
	UCRSaveGame* CurrentSaveGame;

	UPROPERTY(BlueprintReadOnly, Category="LevelData")
	int32 SelectionLevelNumber;
	
	UPROPERTY(BlueprintReadWrite,Category="Settings")
	float MouseSensitivity = 1.f;

	UFUNCTION(BlueprintCallable, Category="SaveGame")
	bool LoadGame();

	UFUNCTION(BlueprintCallable, Category="SaveGame")
	bool SaveGame();
};
