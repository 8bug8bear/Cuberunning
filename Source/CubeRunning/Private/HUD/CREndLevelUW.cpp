// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/CREndLevelUW.h"
#include "Components/TextBlock.h"
#include "Core/CubeRunningGameMode.h"
#include "Kismet/GameplayStatics.h"

void UCREndLevelUW::NativeConstruct()
{
	Super::NativeConstruct();

	ACubeRunningGameMode* GameMode = Cast<ACubeRunningGameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if(IsValid(GameMode))
	{
		int32 Minets = GameMode->GetMatchTime()/60;
		int32 Seconds = GameMode->GetMatchTime()%60;
		
		FText Time = FText::FromString(FString::FromInt(Minets)+" : "+FString::FromInt(Seconds));
		
		PassageTimeText->SetText(Time);
		KilledDragonsText->SetText(FText::FromString(FString::FromInt(GameMode->GetKilledDragons())));
		GEngine->AddOnScreenDebugMessage(-1,5,FColor::Red,"UCREndLevelUW::NativeConstruct::gamemod in valide");
	}
}
