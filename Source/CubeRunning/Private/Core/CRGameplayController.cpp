// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CRGameplayController.h"
#include "Blueprint/UserWidget.h"
#include "Blueprint/WidgetLayoutLibrary.h"

void ACRGameplayController::BeginPlay()
{
	Super::BeginPlay();

	SetShowMouseCursor(false);

	SetInputMode(FInputModeGameOnly());
}

void ACRGameplayController::CharacterWin()
{
	SetPause(true);

	UWidgetLayoutLibrary::RemoveAllWidgets(GetWorld());

	if(EndLevelUWClass)
	{
		UUserWidget* EndLevel = CreateWidget(this, EndLevelUWClass);
		if(EndLevel)
		{
			EndLevel->AddToViewport();
			FInputModeUIOnly InputMode;
			InputMode.SetWidgetToFocus(EndLevel->TakeWidget());
			InputMode.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
			SetInputMode(InputMode);
			SetShowMouseCursor(true);
		}
	}
}
