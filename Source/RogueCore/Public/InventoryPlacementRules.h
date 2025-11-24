#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EUnlockType.h"
#include "ItemSlotIndex.h"
#include "InventoryPlacementRules.generated.h"

class APlayerCharacter;
UCLASS(Blueprintable)
class ROGUECORE_API UInventoryPlacementRules : public UObject {
    GENERATED_BODY()
public:
    UInventoryPlacementRules();
    UFUNCTION(BlueprintCallable)
    static TArray<FItemSlotIndex> GetPlaceableUnlockSlotsFromType(APlayerCharacter* Player, EUnlockType Type, bool& IsFreeSlots);
    
};
