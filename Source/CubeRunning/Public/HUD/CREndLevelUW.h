// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CREndLevelUW.generated.h"

UCLASS()
class CUBERUNNING_API UCREndLevelUW : public UUserWidget
{
	GENERATED_BODY()


protected:
	UPROPERTY(meta=(BindWidget))
	class UTextBlock* PassageTime;
};
