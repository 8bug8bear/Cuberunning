// Fill out your copyright notice in the Description page of Project Settings.


#include "Environment/CRSelfDestructingPlatform.h"

void ACRSelfDestructingPlatform::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(CheckDistansTimerHandl,this,&ACRSelfDestructingPlatform::CheckDistans,FrequencyInspections, true);
}

void ACRSelfDestructingPlatform::CheckDistans()
{
	float Distans = FVector::Distance(GetActorLocation(), GetWorld()->GetFirstPlayerController()->GetFocalLocation());
	
	if(Distans<=DistanceToDestroy)
	{
		MakeVisualBeforeDestruction();
		GetWorldTimerManager().ClearTimer(CheckDistansTimerHandl);
		GetWorldTimerManager().SetTimer(DestroyPlatformTimerHandle,this,&ACRSelfDestructingPlatform::DestroyThisPlatform,TimeToDestroy);
	}
}

void ACRSelfDestructingPlatform::DestroyThisPlatform()
{
	Destroy();
}

void ACRSelfDestructingPlatform::MakeVisualBeforeDestruction()
{
	if(PlatformMaterialInstance)
	{
		//GEngine->AddOnScreenDebugMessage(-1,5,FColor::Green,"Oll right");
		PlatformMaterialInstance->SetScalarParameterValue("GlowIntensity",0.f);
	}
}

