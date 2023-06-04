#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventoryComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventoryUpdated);

class UItem; // Forward declaration
class AInventorySystemCharacter; // Forward declaration

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class INVENTORYSYSTEM_API UInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UInventoryComponent();

    UPROPERTY(BlueprintAssignable, Category = "Inventory")
        FOnInventoryUpdated OnInventoryUpdated;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Items")
        TArray<UItem*> Items;

    virtual void BeginPlay() override;

    bool AddItem(UItem* Item);

    bool RemoveItem(UItem* Item);

    UPROPERTY(EditDefaultsOnly, Instanced)
        TArray<UItem*> DefaultsItem = {};

    UPROPERTY(EditDefaultsOnly, Category = "Inventory")
        int32 Capacity;
};
