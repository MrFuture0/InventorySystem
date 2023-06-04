#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "InventoryComponent.h"
#include "InventorySystemCharacter.h"
#include "FoodItem.generated.h"

class UInventoryComponent; // Forward declaration
class AInventorySystemCharacter; // Forward declaration

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
};
