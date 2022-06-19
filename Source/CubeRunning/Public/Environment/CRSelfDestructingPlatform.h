// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Environment/CRPlatform.h"
#include "CRSelfDestructingPlatform.generated.h"

/**
 * 
 */
UCLASS()
class CUBERUNNING_API ACRSelfDestructingPlatform : public ACRplatform
{
	GENERATED_BODY()

public:
	FTimerHandle CheckDistansTimerHandl;
	FTimerHandle DestroyPlatformTimerHandle;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Destruction")
	float DistanceToDestroy = 800;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Destruction")
	float TimeToDestroy = 1.f;

protected:
	UPROPERTY(EditAnywhere,BlueprintReadOnly, Category="Destruction")
	float FrequencyInspections = 0.3f;
	
	virtual void BeginPlay() override;

	UFUNCTION()
	void CheckDistans();

	UFUNCTION()
	void DestroyThisPlatform();

	UFUNCTION()
	void MakeVisualBeforeDestruction();
};
