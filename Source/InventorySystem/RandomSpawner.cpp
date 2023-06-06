// Fill out your copyright notice in the Description page of Project Settings.


#include "RandomSpawner.h"
#include "TriggerActor.h"


// Sets default values
ARandomSpawner::ARandomSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ARandomSpawner::BeginPlay()
{
    Super::BeginPlay();
    SpawnTriggers();
}

void ARandomSpawner::SpawnTriggers()
{
    for (int32 i = 0; i < NumberOfTriggersToSpawn; i++)
    {
        // Random spawn location within the specified area extent
        FVector SpawnLocation = FMath::RandPointInBox(FBox(FVector(-SpawnAreaExtent.X, -SpawnAreaExtent.Y, 133.f), FVector(SpawnAreaExtent.X, SpawnAreaExtent.Y, 133.f)));


        // Spawn the trigger actor
        ATriggerActor* TriggerActor = GetWorld()->SpawnActor<ATriggerActor>(TriggerActorClass, SpawnLocation, FRotator::ZeroRotator);
    }
}





