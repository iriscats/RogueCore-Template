#pragma once
#include "CoreMinimal.h"
#include "ItemAquisitionBase.h"
#include "StoreBoughtAquisition.generated.h"

class UResourceData;
UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UStoreBoughtAquisition : public UItemAquisitionBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CreditsCost;
    
    TMap<UResourceData*, float> ResourceCost;
    int32 RequiredPlayerRank;
    UStoreBoughtAquisition();
};
