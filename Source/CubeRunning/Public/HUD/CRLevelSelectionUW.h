// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CRLevelSelectionUW.generated.h"

class UTextBlock;

UCLASS()
class CUBERUNNING_API UCRLevelSelectionUW : public UUserWidget
{
	GENERATED_BODY()

protected:
	UPROPERTY(BlueprintReadOnly, Category="Owner")
	UUserWidget* OwnerWidget;

	UPROPERTY(meta=(BindWidget))
	class UImage* SelectionLevelImage;

	UPROPERTY(meta=(BindWidget))
	UTextBlock* PassageTime;

	UPROPERTY(meta=(BindWidget))
	class UTextBlock* KilledDragons;

	UPROPERTY(meta=(BindWidget))
	class UButton* SelectLevel;

	FName SelectionLevelName;

	UFUNCTION()
	void OpenSelectedlevel();
	
public:
	UFUNCTION(BlueprintCallable, Category="UsersFunctions")
	void SetOwnerWidget(UUserWidget* Widget);

	UFUNCTION(BlueprintCallable, Category="UsersFunctions")
	void SetDatasSelectionLevel(UTexture2D* Image, FName LevelName, int32 LevelNumber);
	
	virtual void NativeConstruct() override;
};
