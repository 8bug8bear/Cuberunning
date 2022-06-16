// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CRPortal.generated.h"

UCLASS()
class CUBERUNNING_API ACRPortal : public AActor
{
	GENERATED_BODY()


protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	class UBoxComponent* CollisionBox;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* PortalMesh;

	UPROPERTY(EditAnywhere,BlueprintReadOnly, meta=(MakeEditWidget), Category="Teleportatio")
	FVector TeleportationPoint;

	virtual void BeginPlay() override;
	
public:	
	// Sets default values for this actor's properties
	ACRPortal();
	
	UFUNCTION()
	void OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
