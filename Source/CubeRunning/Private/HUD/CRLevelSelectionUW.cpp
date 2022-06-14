// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/CRLevelSelectionUW.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"
#include "Core/CRGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "Pluggable/Definitions.h"


void UCRLevelSelectionUW::OpenSelectedlevel()
{
	UGameplayStatics::OpenLevel(GetWorld(),SelectionLevelName);
}

void UCRLevelSelectionUW::SetOwnerWidget(UUserWidget* Widget)
{
	if(!IsValid(OwnerWidget))
	{
		OwnerWidget = Widget;
	}
}

void UCRLevelSelectionUW::SetDatasSelectionLevel(UTexture2D* Image, FName LevelName, int32 LevelNumber)
{
	SelectionLevelImage->SetBrushFromTexture(Image);
	SelectionLevelName = LevelName;
	
	if(CurentGameInstance != nullptr)
	{
		CurentGameInstance->SelectionLevelNumber = LevelNumber;

		if(CurentGameInstance->CurrentSaveGame!=nullptr)
		{
			int32 PassageTime = CurentGameInstance->CurrentSaveGame->LevelItemsArr[LevelNumber].PassageTime;
			int32 KilledDrons = CurentGameInstance->CurrentSaveGame->LevelItemsArr[LevelNumber].KilledDragons;
			
			PassageTimeText->SetText(IntToTimeText(PassageTime));
			KilledDragonsText->SetText(FText::FromString(FString::FromInt(KilledDrons)));
		}
	}
}

void UCRLevelSelectionUW::NativeConstruct()
{
	Super::NativeConstruct();
	
	SelectLevel->OnClicked.AddDynamic(this,&UCRLevelSelectionUW::OpenSelectedlevel);
	
	CurentGameInstance = Cast<UCRGameInstance>(GetGameInstance());
}
