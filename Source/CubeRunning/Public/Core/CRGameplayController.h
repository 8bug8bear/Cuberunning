// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CRGameplayController.generated.h"

/**
 * 
 */
UCLASS()
class CUBERUNNING_API ACRGameplayController : public APlayerController
{
	GENERATED_BODY()

	
protected:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly, Category = "UserWidget")
	TSubclassOf<UUserWidget> EndLevelUWClass;
	
	virtual void BeginPlay() override;
	
public:
	void CharacterWin();
};
