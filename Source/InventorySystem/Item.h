#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventoryComponent.h"
#include "InventorySystemCharacter.h"
#include "Item.generated.h"

class UInventoryComponent; // Forward declaration
class AInventorySystemCharacter; // Forward declaration

UCLASS(Abstract, BlueprintType, Blueprintable, EditInlineNew, DefaultToInstanced)
class INVENTORYSYSTEM_API UItem : public UObject
{
    GENERATED_BODY()

public:
    UItem();

    virtual class UWorld* GetWorld() const override { return World; }

    UPROPERTY(Transient)
        class UWorld* World;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
        FText UseActionText;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
        class UStaticMesh* PickupMesh;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
        class UTexture2D* Thumbnail;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item")
        FText ItemDisplayName;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (MultiLine = true))
        FText ItemDescription;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
        float Weight;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
        int32 StackCount;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
        int32 MaxStack;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
        float VestHealth;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Item", meta = (ClampMin = 0.0))
        int VestStackCount;

    UPROPERTY()
        UInventoryComponent* OwningInventory;

    virtual void Use(AInventorySystemCharacter* Character);

    UFUNCTION(BlueprintImplementableEvent)
        void OnUse(AInventorySystemCharacter* Character);
};
