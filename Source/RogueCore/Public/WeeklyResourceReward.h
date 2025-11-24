#pragma once
#include "CoreMinimal.h"
#include "IRandRange.h"
#include "Reward.h"
#include "WeeklyResourceReward.generated.h"

class AFSDPlayerController;
class UResourceData;
UCLASS(Blueprintable, EditInlineNew)
class UWeeklyResourceReward : public UReward {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ResourceCount;
    
    FIRandRange amount;
    UWeeklyResourceReward();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TMap<UResourceData*, float> GetRewards(AFSDPlayerController* Player) const;
};
