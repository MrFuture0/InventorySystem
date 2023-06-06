#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "InventoryComponent.h"
#include "InventorySystemCharacter.h"
#include "FoodItem.generated.h"

class UInventoryComponent; // Forward declaration
class AInventorySystemCharacter; // Forward declaration
class AActor;

UCLASS()
class INVENTORYSYSTEM_API UFoodItem : public UItem
{
    GENERATED_BODY()

protected:
    virtual void Use(AInventorySystemCharacter* Character) override;

public:
    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
        int32 FoodStackCount;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
        int32 FoodMaxStack;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
        float HealthToHeal;

    void* operator new(size_t Size);
    void operator delete(void* Ptr, size_t Size);

    void AddToInventory(UInventoryComponent* InventoryComponent, AActor* OwningActor);

    // Ekmek öğesini sahibi olan aktörün referansını tutacak değişken
    UPROPERTY()
        AActor* OwnerActor;

};
