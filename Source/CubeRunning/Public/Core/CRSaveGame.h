// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "CRSaveGame.generated.h"

USTRUCT()
struct FLevelItem
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category="LevelInfo")
	int32 PassageTime;

	UPROPERTY(EditDefaultsOnly, Category="LevelInfo")
	int32 KilledDragons;

	UPROPERTY(EditDefaultsOnly, Category="LevelInfo")
	bool bIsLevelPassed;
};


UCLASS()
class CUBERUNNING_API UCRSaveGame : public USaveGame
{
	GENERATED_BODY()


public:
	UPROPERTY()
	TArray<FLevelItem> LevelItemsArr;

	const int32 NumberOfLevels = 5;

	void ComplitLevelItems();
};
