// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/CRLevelSelectionUW.h"
#include "Components/Button.h"
#include "Components/Image.h"
#include "Kismet/GameplayStatics.h"


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

	/*
	 * Loading informations of level from game save
	 */
}

void UCRLevelSelectionUW::NativeConstruct()
{
	Super::NativeConstruct();
	
	SelectLevel->OnClicked.AddDynamic(this,&UCRLevelSelectionUW::OpenSelectedlevel);
}
