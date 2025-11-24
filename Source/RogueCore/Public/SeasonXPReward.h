#pragma once
#include "CoreMinimal.h"
#include "Reward.h"
#include "SeasonXPReward.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class USeasonXPReward : public UReward {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 amount;
    
    USeasonXPReward();
};
