#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EDealType.h"
#include "DailyDealSetup.generated.h"

class UResourceData;
USTRUCT(BlueprintType)
struct FDailyDealSetup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UResourceData* Resource;
    
    EDealType DealType;
    FIntPoint UnitsRange;
    FVector2D DiscountRangePercent;
    FVector2D ExtraValueRangePercent;
    ROGUECORE_API FDailyDealSetup();
};
