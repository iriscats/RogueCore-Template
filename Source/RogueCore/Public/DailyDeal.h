#pragma once
#include "CoreMinimal.h"
#include "EDealType.h"
#include "DailyDeal.generated.h"

class UResourceData;
USTRUCT(BlueprintType)
struct FDailyDeal {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UResourceData* Resource;
    
    EDealType DealType;
    int32 ResourceAmount;
    int32 Credits;
    float ChangePercent;
    ROGUECORE_API FDailyDeal();
};
