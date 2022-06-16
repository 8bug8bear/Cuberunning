// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/CREndLevelUW.h"
#include "Components/TextBlock.h"
#include "Core/CRGameInstance.h"
#include "Core/CubeRunningGameMode.h"
#include "Pluggable/Definitions.h"
#include "Kismet/GameplayStatics.h"

void UCREndLevelUW::NativeConstruct()
{
	Super::NativeConstruct();

	ACubeRunningGameMode* GameMode = Cast<ACubeRunningGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if(IsValid(GameMode))
	{
		FText CurentTime = IntToTimeText(GameMode->GetMatchTime());
		FText BestTime;
		
		if(UCRGameInstance* GameInstance = Cast<UCRGameInstance>(GetGameInstance()))
		{
			int32 SelectionLevelNumber = GameInstance->SelectionLevelNumber;
			BestTime = IntToTimeText(GameInstance->CurrentSaveGame->LevelItemsArr[SelectionLevelNumber].PassageTime);
		}
		
		PassageTimeText->SetText(CurentTime);
		BestPassageTimetext->SetText(BestTime);
		KilledDragonsText->SetText(FText::FromString(FString::FromInt(GameMode->GetKilledDragons())));
		GEngine->AddOnScreenDebugMessage(-1,5,FColor::Red,"UCREndLevelUW::NativeConstruct::gamemod in valide");
	}
}
