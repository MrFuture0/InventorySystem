// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerActor.h"
#include "FoodItem.h"
#include "InventoryComponent.h"
#include "InventorySystemCharacter.h"

// Sets default values
ATriggerActor::ATriggerActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	RootComponent = BoxComponent;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ATriggerActor::TriggerActive);
}

// Called when the game starts or when spawned
void ATriggerActor::BeginPlay()
{
    Super::BeginPlay();

    UBlueprint* BP_Bread = LoadObject<UBlueprint>(nullptr, TEXT("'/Game/ThirdPersonCPP/Blueprints/BP_Bread.BP_Bread'")); // BP_Bread'ın doğru yolu ile değiştirin
    if (BP_Bread)
    {
        UFoodItem* BreadItem = Cast<UFoodItem>(BP_Bread->GeneratedClass->GetDefaultObject());
        if (BreadItem)
        {
            BreadItem->FoodStackCount = 0; // FoodStackCount'u sıfırla
        }
    }
}


// Called every frame
void ATriggerActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATriggerActor::TriggerActive(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    AInventorySystemCharacter* Character = Cast<AInventorySystemCharacter>(OtherActor);
    if (Character)
    {
        UInventoryComponent* InventoryComponent = Character->FindComponentByClass<UInventoryComponent>();
        if (InventoryComponent)
        {
            UBlueprint* BP_Bread = LoadObject<UBlueprint>(nullptr, TEXT("'/Game/ThirdPersonCPP/Blueprints/BP_Bread.BP_Bread'")); // BP_Bread'ın doğru yolu ile değiştirin
            if (BP_Bread)
            {
                UFoodItem* BreadItem = Cast<UFoodItem>(BP_Bread->GeneratedClass->GetDefaultObject());
                if (BreadItem)
                {
                    // FoodStackCount değerine göre davranış belirle
                    if (BreadItem->FoodStackCount <= 0)
                    {
                        InventoryComponent->AddItem(BreadItem);
                        BreadItem->FoodStackCount += 1; // FoodStackCount'u artir
                    }
                    else
                    {
                        BreadItem->FoodStackCount += 1; // FoodStackCount'u artir
                    }
                    UE_LOG(LogTemp, Warning, TEXT("Bread Count : %i"),BreadItem->FoodStackCount);
                }
            }
        }
    }
}











