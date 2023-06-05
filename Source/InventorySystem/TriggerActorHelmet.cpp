// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerActorHelmet.h"
#include "InventorySystemCharacter.h"
#include "InventoryComponent.h"
#include "Item.h"

// Sets default values
ATriggerActorHelmet::ATriggerActorHelmet()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComp"));
	RootComponent = BoxComponent;

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootComponent);

	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ATriggerActorHelmet::TriggerActiveHelmet);
}

// Called when the game starts or when spawned
void ATriggerActorHelmet::BeginPlay()
{
	Super::BeginPlay();

	UBlueprint* BP_Helmet = LoadObject<UBlueprint>(nullptr, TEXT("'/Game/ThirdPersonCPP/Blueprints/BP_Helmet.BP_Helmet'")); //BP_Vest
	if (BP_Helmet)
	{
		UItem* BP_Helmet_Item = Cast<UItem>(BP_Helmet->GeneratedClass->GetDefaultObject());
		if (BP_Helmet_Item)
		{
            BP_Helmet_Item->HelmetHealth = 100.f;
            BP_Helmet_Item->HelmetStackCount = 0;
		}
	}
	
}

// Called every frame
void ATriggerActorHelmet::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void ATriggerActorHelmet::TriggerActiveHelmet(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    AInventorySystemCharacter* Character = Cast<AInventorySystemCharacter>(OtherActor);
    if (Character)
    {
        UInventoryComponent* InventoryComponent = Character->FindComponentByClass<UInventoryComponent>();
        if (InventoryComponent)
        {
            UBlueprint* BP_Helmet = LoadObject<UBlueprint>(nullptr, TEXT("'/Game/ThirdPersonCPP/Blueprints/BP_Helmet.BP_Helmet'")); //BP_Vest
            if (BP_Helmet)
            {
                UItem* BP_Helmet_Item = Cast<UItem>(BP_Helmet->GeneratedClass->GetDefaultObject());
                if (BP_Helmet_Item)
                {
                    if (BP_Helmet_Item->HelmetStackCount <= 0)
                    {
                        InventoryComponent->AddItem(BP_Helmet_Item);
                        BP_Helmet_Item->HelmetStackCount += 1;
                    }
                    else
                    {
                        BP_Helmet_Item->HelmetHealth = 100.f;
                    }
                }
                UE_LOG(LogTemp, Warning, TEXT("Helmet Count  : %i"), BP_Helmet_Item->HelmetStackCount);
                UE_LOG(LogTemp, Warning, TEXT("Helmet Health  : %f"), BP_Helmet_Item->HelmetHealth);
            }
        }
    }

}
