// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/CREndLevelUW.h"
#include "Components/TextBlock.h"
#include "Core/CubeRunningGameMode.h"
#include "Pluggable/Definitions.h"
#include "Kismet/GameplayStatics.h"

void UCREndLevelUW::NativeConstruct()
{
	Super::NativeConstruct();

	ACubeRunningGameMode* GameMode = Cast<ACubeRunningGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if(IsValid(GameMode))
	{
		FText Time = IntToTimeText(GameMode->GetMatchTime());
		
		PassageTimeText->SetText(Time);
		KilledDragonsText->SetText(FText::FromString(FString::FromInt(GameMode->GetKilledDragons())));
		GEngine->AddOnScreenDebugMessage(-1,5,FColor::Red,"UCREndLevelUW::NativeConstruct::gamemod in valide");
	}
}
