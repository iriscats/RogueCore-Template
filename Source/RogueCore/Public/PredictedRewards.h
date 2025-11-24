#pragma once
#include "CoreMinimal.h"
#include "ExcavationReward.h"
#include "PredictedRewards.generated.h"

USTRUCT(BlueprintType)
struct FPredictedRewards {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FExcavationReward> Rewards;
    
    TArray<int32> Counts;
    ROGUECORE_API FPredictedRewards();
};
