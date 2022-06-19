// Fill out your copyright notice in the Description page of Project Settings.


#include "Environment/CRPlatform.h"


ACRplatform::ACRplatform()
{
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	PlatformMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Platform"));
	PlatformMesh->SetupAttachment(RootComponent);
}

void ACRplatform::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);

	switch (PlatformsTupe)
	{
	case EPlatformsTupe::flat:
		if(PlatformMeshFlat)
		{
			PlatformMesh->SetStaticMesh(PlatformMeshFlat);
		}
		break;
		
	case EPlatformsTupe::cruciform:
		if(PlatformMeshFlat)
		{
			PlatformMesh->SetStaticMesh(PlatformMeshCruciform);
		}
		break;
		
	default:
		if(PlatformMeshFlat)
		{
			PlatformMesh->SetStaticMesh(PlatformMeshCruciform);
		}
	}
}


void ACRplatform::BeginPlay()
{
	Super::BeginPlay();

	switch (PlatformsTupe)
	{
	case EPlatformsTupe::flat:
		if(PlatformMaterialFlat)
		{
			PlatformMaterialInstance = UMaterialInstanceDynamic::Create(PlatformMaterialFlat,PlatformMesh);
		}
		break;
		
	case EPlatformsTupe::cruciform:
		if(PlatformMaterialFlat)
		{
			PlatformMaterialInstance = UMaterialInstanceDynamic::Create(PlatformMaterialCruciform,PlatformMesh);
		}
		break;
		
	default:
		if(PlatformMaterialFlat)
		{
			PlatformMaterialInstance = UMaterialInstanceDynamic::Create(PlatformMaterialFlat,PlatformMesh);
		}
	}
	
	PlatformMesh->SetMaterial(0,PlatformMaterialInstance);
}


void ACRplatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

