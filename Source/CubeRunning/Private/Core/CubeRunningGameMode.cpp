// Copyright Epic Games, Inc. All Rights Reserved.

#include "Core/CubeRunningGameMode.h"
#include "Character/CubeRunningCharacter.h"
#include "Core/CRGameInstance.h"
#include "Core/CRGameplayController.h"
#include "GameFramework/GameMode.h"
#include "Kismet/GameplayStatics.h"


ACubeRunningGameMode::ACubeRunningGameMode()
	: Super(){}

void ACubeRunningGameMode::GameСharacterDied()
{
	GetWorldTimerManager().ClearTimer(UpdateLifetimeTimerHandle);
	LevelReboot();
}

void ACubeRunningGameMode::CharacterWin()
{
	GetWorldTimerManager().ClearTimer(UpdateLifetimeTimerHandle);

	ACRGameplayController* GameplayController = Cast<ACRGameplayController>(GetWorld()->GetFirstPlayerController());
	if(IsValid(GameplayController))
	{
		GameplayController->CharacterWin();
	}
	int32 SelectionLevelNumber;
	UCRGameInstance* GameInstance = Cast<UCRGameInstance>(GetGameInstance());
	if(GameInstance)
	{
		SelectionLevelNumber = GameInstance->SelectionLevelNumber;
		if(GameInstance->CurrentSaveGame)
		{
			GameInstance->CurrentSaveGame->LevelItemsArr[SelectionLevelNumber].KilledDragons = KilledDragons;
			GameInstance->CurrentSaveGame->LevelItemsArr[SelectionLevelNumber].PassageTime = MatchTime;
			GameInstance->CurrentSaveGame->LevelItemsArr[SelectionLevelNumber].bIsLevelPassed=true;

			GameInstance->SaveGame();
		}
	}
}

void ACubeRunningGameMode::LevelReboot()
{
	UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
}

int32 ACubeRunningGameMode::AddLifeTime(int32 Added)
{
	if(Added < 1)
	{
		return -1;
	}

	LifeTime+=Added;
	OnUpdateLifetime.Broadcast(LifeTime);
	return LifeTime;
}

void ACubeRunningGameMode::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(UpdateLifetimeTimerHandle,this,&ACubeRunningGameMode::UpdateLifetime,1.f, true);

	GetWorldTimerManager().SetTimer(UpdateMatchTimeTimerHandle,this,&ACubeRunningGameMode::UpdateMatchTimeTime,1.f,true);
}

void ACubeRunningGameMode::UpdateLifetime()
{
	LifeTime--;
	//GEngine->AddOnScreenDebugMessage(-1,1.f,FColor::Green,FString::Printf(TEXT("LifeTime = %d"),LifeTime));
	if(LifeTime <= 0)
	{
		LifeTime = 0;
		GetWorldTimerManager().ClearTimer(UpdateLifetimeTimerHandle);
		if(GameСharacter.IsValid())
		{
			GameСharacter->GetHealthComponent()->Death();
		}
		else
		{
			LevelReboot();
		}
	}
	OnUpdateLifetime.Broadcast(LifeTime);
}
