#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "IRandRange.h"
#include "PricingTierEntry.generated.h"

USTRUCT(BlueprintType)
struct FPricingTierEntry : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FIRandRange CreditCost;
    
    FIRandRange Material1;
    FIRandRange Material2;
    FIRandRange Material3;
    ROGUECORE_API FPricingTierEntry();
};
