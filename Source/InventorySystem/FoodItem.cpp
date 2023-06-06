#include "FoodItem.h"
#include "Item.h"
#include "InventoryComponent.h"
#include "InventorySystemCharacter.h"

void UFoodItem::Use(AInventorySystemCharacter* Character)
{
    if (Character)
    {
        Character->Health += HealthToHeal;
        
        GEngine->AddOnScreenDebugMessage(0, 1.f, FColor::Green, FString(TEXT("Bread used added 20 health")), true);
        if (OwningInventory)
        {
            if (FoodStackCount > 0)
            {
                FoodStackCount -= 1;
                if (FoodStackCount <= 0)
                {
                    OwningInventory->RemoveItem(this);
                    UE_LOG(LogTemp, Warning, TEXT("bread is out of stock"));
                }
            }
        }
    }
}


void* UFoodItem::operator new(size_t Size)
{
    return FMemory::Malloc(Size);
    UE_LOG(LogTemp, Warning, TEXT("new operator"));
}

void UFoodItem::operator delete(void* Ptr, size_t Size)
{
    FMemory::Free(Ptr);
    UE_LOG(LogTemp, Warning, TEXT("delete operator"));
}

void UFoodItem::AddToInventory(UInventoryComponent* InventoryComponent, AActor* OwningActor)
{
        // Ekmek öğesini envantere ekle
        InventoryComponent->AddItem(this);

        // Ekmek nesnesini sahibi olan aktörün referansıyla güncelle
        this->OwnerActor = OwningActor;
}






