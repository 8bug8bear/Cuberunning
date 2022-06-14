// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CRGameInstance.h"
#include "Pluggable/Definitions.h"
#include "Kismet/GameplayStatics.h"


bool UCRGameInstance::LoadGame()
{
	if(CurrentSaveGame)
	{
		return true;
	}
	if(UGameplayStatics::DoesSaveGameExist(SaveSlotName,0))
	{
		USaveGame* NewSaveGame = UGameplayStatics::LoadGameFromSlot(SaveSlotName, 0);
		if(!NewSaveGame)return false;
	
		CurrentSaveGame = Cast<UCRSaveGame>(NewSaveGame);
		if(!CurrentSaveGame)return true;
	}
	else
	{
		USaveGame* NewSaveGame = UGameplayStatics::CreateSaveGameObject(UCRSaveGame::StaticClass());
		if(!NewSaveGame)return false;
		
		CurrentSaveGame = Cast<UCRSaveGame>(NewSaveGame);
		if(CurrentSaveGame)
		{
			CurrentSaveGame->ComplitLevelItems();
			SaveGame();
			return true;
		}
		return false;
	}
	
	return false;
}

bool UCRGameInstance::SaveGame()
{
	if(CurrentSaveGame)
	{
		return UGameplayStatics::SaveGameToSlot(CurrentSaveGame, SaveSlotName,0);
	}

	return false;
}
