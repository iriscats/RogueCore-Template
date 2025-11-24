#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ItemSlotIndex.h"
#include "UnlockableWithCount.h"
#include "UnlockableTypeData.generated.h"

USTRUCT(BlueprintType)
struct ROGUECORE_API FUnlockableTypeData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid Unlock;
    
    FGuid Rarity;
    FGuid ItemID;
    uint8 count;
    FItemSlotIndex SelectedSlot;
    TArray<FUnlockableWithCount> Attributes;
    FUnlockableTypeData();
};
