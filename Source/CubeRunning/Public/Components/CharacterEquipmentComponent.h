// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Equipment/BaseWeapon.h"
#include "CharacterEquipmentComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class CUBERUNNING_API UCharacterEquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

	

protected:
	UPROPERTY()
	ABaseWeapon* EquipWeapon;

	// Weapon class template
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Loadout ")
	TSubclassOf<ABaseWeapon> LoadoutWeapon;

	// Weak reference to the gun owner
	TWeakObjectPtr<class ACubeRunningCharacter> CachedCharacterOwner;

	// Called when the game starts
	virtual void BeginPlay() override;

	//
	void CreateLodout();

public:	
	// Sets default values for this component's properties
	UCharacterEquipmentComponent();

	// Returns a link to the equipped weapon
	ABaseWeapon* GetEquippedWeapon()const {return EquipWeapon;}
};
