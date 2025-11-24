#pragma once
#include "CoreMinimal.h"
#include "ItemSlotArgs.generated.h"

class UItemID;
class UItemUpgrade;
USTRUCT(BlueprintType)
struct FItemSlotArgs {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UItemUpgrade*> ItemUpgrades;
    
    UItemID* ItemID;
    bool IsRestoringState;
    ROGUECORE_API FItemSlotArgs();
};
