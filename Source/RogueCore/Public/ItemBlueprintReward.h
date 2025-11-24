#pragma once
#include "CoreMinimal.h"
#include "UnlockReward.h"
#include "ItemBlueprintReward.generated.h"

class UItemID;
UCLASS(Blueprintable, EditInlineNew)
class UItemBlueprintReward : public UUnlockReward {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UItemID* ItemID;
    
    UItemBlueprintReward();
};
