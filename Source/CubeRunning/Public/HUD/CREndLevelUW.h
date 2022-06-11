// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CREndLevelUW.generated.h"

class UTextBlock;

UCLASS()
class CUBERUNNING_API UCREndLevelUW : public UUserWidget
{
	GENERATED_BODY()


protected:
	UPROPERTY(meta=(BindWidget))
	UTextBlock* PassageTimeText;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* KilledDragonsText;

public:
	virtual void NativeConstruct() override;
};
