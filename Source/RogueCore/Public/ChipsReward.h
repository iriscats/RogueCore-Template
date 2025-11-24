#pragma once
#include "CoreMinimal.h"
#include "ChipsReward.generated.h"

USTRUCT(BlueprintType)
struct FChipsReward {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NewChips;
    
    int32 PreReclaimerPoints;
    int32 PostReclaimerPoints;
    int32 PreRemainingReclaimerPoints;
    int32 PostRemainingReclaimerPoints;
    int32 RawReclaimerPoints;
    int32 ConversionRate;
    TArray<int32> ConversionRates;
    int32 CollectedCameras;
    int32 PreLevel;
    int32 PostLevel;
    int32 MaxLevel;
    float ReclaimerPointBonusMultiplier;
    ROGUECORE_API FChipsReward();
};
