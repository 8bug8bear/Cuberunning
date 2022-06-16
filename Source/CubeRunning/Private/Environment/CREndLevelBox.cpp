// Fill out your copyright notice in the Description page of Project Settings.


#include "Environment/CREndLevelBox.h"
#include "Components/BoxComponent.h"
#include "Core/CubeRunningGameMode.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ACREndLevelBox::ACREndLevelBox()
{
	TrigerBox = CreateDefaultSubobject<UBoxComponent>(TEXT("TrigerBox"));

}

void ACREndLevelBox::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(!OtherActor->IsA<ACharacter>()) return;
	
	ACubeRunningGameMode* GameMode = Cast<ACubeRunningGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

	if(IsValid(GameMode))
	{
		GameMode->CharacterWin();
	}
}

void ACREndLevelBox::BeginPlay()
{
	Super::BeginPlay();

	TrigerBox->OnComponentBeginOverlap.AddDynamic(this, &ACREndLevelBox::OnComponentBeginOverlap);
}

