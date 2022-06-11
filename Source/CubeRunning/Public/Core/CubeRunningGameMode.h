// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CubeRunningGameMode.generated.h"

DECLARE_MULTICAST_DELEGATE_OneParam(FUpdateLifetime,int32);

UCLASS(minimalapi)
class ACubeRunningGameMode : public AGameModeBase
{
	GENERATED_BODY()

	
protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category="Time")
	int32 LifeTime;
	
	UPROPERTY(BlueprintReadOnly, Category="Time")
	int32 MatchTime = 0;

	UPROPERTY(BlueprintReadOnly, Category="Time")
	int32 KilledDragons = 0;

	FTimerHandle UpdateMatchTimeTimerHandle;

public:
	TWeakObjectPtr<class ACubeRunningCharacter> GameСharacter;
	
	FTimerHandle UpdateLifetimeTimerHandle;

	FUpdateLifetime OnUpdateLifetime;
	
	ACubeRunningGameMode();
	
	void GameСharacterDied();

	void CharacterWin();

	int32 GetLifeTime() const {return LifeTime;}

	int32 GetMatchTime() const {return MatchTime;}

	// Increases the LifeTime by the passed value and returns a new LifeTime. If the passed value is incorrect, it returns -1
	int32 AddLifeTime(int32 Added);

	int32 GetKilledDragons() const {return KilledDragons;}

	void AddKilledDragons(){KilledDragons++;}
	
protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void UpdateLifetime();

	void LevelReboot();

	UFUNCTION()
	void UpdateMatchTimeTime(){MatchTime++;};
};



