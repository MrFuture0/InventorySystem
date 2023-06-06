// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RandomSpawner.generated.h"

UCLASS()
class INVENTORYSYSTEM_API ARandomSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARandomSpawner();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

private:
    UPROPERTY(EditAnywhere, Category = "Spawner")
        TSubclassOf<class ATriggerActor> TriggerActorClass;

    UPROPERTY(EditAnywhere, Category = "Spawner")
        int32 NumberOfTriggersToSpawn;

    UPROPERTY(EditAnywhere, Category = "Spawner")
        FVector SpawnAreaExtent;

    void SpawnTriggers();

};
