// Fill out your copyright notice in the Description page of Project Settings.

#include "TriggerActorVest.h"
#include "InventorySystemCharacter.h"
#include "InventoryComponent.h"
#include "Item.h"

// Sets default values
ATriggerActorVest::ATriggerActorVest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	RootComponent = BoxComponent;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ATriggerActorVest::TriggerActive);
}

// Called when the game starts or when spawned
void ATriggerActorVest::BeginPlay()
{
	Super::BeginPlay();
    UBlueprint* BP_Vest = LoadObject<UBlueprint>(nullptr, TEXT("'/Game/ThirdPersonCPP/Blueprints/BP_Vest.BP_Vest'")); //BP_Vest
    if (BP_Vest)
    {
         UItem* BP_Vest_Item = Cast<UItem>(BP_Vest->GeneratedClass->GetDefaultObject());
         if (BP_Vest_Item)
         {
             BP_Vest_Item->VestHealth = 100.f;
             BP_Vest_Item->VestStackCount = 0;
         }
     }
         
}

// Called every frame
void ATriggerActorVest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ATriggerActorVest::TriggerActive(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    AInventorySystemCharacter* Character = Cast<AInventorySystemCharacter>(OtherActor);
    if (Character)
    {
        UInventoryComponent* InventoryComponent = Character->FindComponentByClass<UInventoryComponent>();
        if (InventoryComponent)
        {
            UBlueprint* BP_Vest = LoadObject<UBlueprint>(nullptr, TEXT("'/Game/ThirdPersonCPP/Blueprints/BP_Vest.BP_Vest'")); //BP_Vest
            if (BP_Vest)
            {
                UItem* BP_Vest_Item = Cast<UItem>(BP_Vest->GeneratedClass->GetDefaultObject());
                if (BP_Vest_Item)
                {
                    if (BP_Vest_Item->VestStackCount <= 0)
                    {
                        InventoryComponent->AddItem(BP_Vest_Item);
                        BP_Vest_Item->VestStackCount += 1;
                    }
                    else
                    {
                        BP_Vest_Item->VestHealth = 100.f;
                    }
                }
                UE_LOG(LogTemp, Warning, TEXT("Vest Count  : %i"), BP_Vest_Item->VestStackCount);
                UE_LOG(LogTemp, Warning, TEXT("Vest Health  : %f"), BP_Vest_Item->VestHealth);
            }
        }
    }

}

