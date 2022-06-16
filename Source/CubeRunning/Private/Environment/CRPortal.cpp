// Fill out your copyright notice in the Description page of Project Settings.


#include "Environment/CRPortal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Character.h"

// Sets default values
ACRPortal::ACRPortal()
{
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("PortalRoot"));
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	PortalMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Portal"));

	PortalMesh->SetupAttachment(RootComponent);
	CollisionBox->SetupAttachment(PortalMesh);
}

void ACRPortal::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if(!OtherActor->IsA<ACharacter>()) return;
	
	OtherActor->SetActorLocation(TeleportationPoint+GetActorLocation());
}

// Called when the game starts or when spawned
void ACRPortal::BeginPlay()
{
	Super::BeginPlay();


	CollisionBox->OnComponentBeginOverlap.AddDynamic(this,&ACRPortal::OnComponentBeginOverlap);
}
