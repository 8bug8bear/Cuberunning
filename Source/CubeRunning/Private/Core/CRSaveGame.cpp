// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CRSaveGame.h"


void UCRSaveGame::ComplitLevelItems()
{
	for(int i = 0; i<NumberOfLevels;i++)
	{
		FLevelItem NewLevelItem;
		NewLevelItem.PassageTime = 0;
		NewLevelItem.KilledDragons = 0;
		NewLevelItem.bIsLevelPassed = false;
		LevelItemsArr.Add(NewLevelItem);
	}
}
