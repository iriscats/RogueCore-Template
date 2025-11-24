#pragma once
#include "CoreMinimal.h"
#include "UnlockReward.h"
#include "UnlockDurationReward.generated.h"

class UStageDuration;
UCLASS(Blueprintable, EditInlineNew)
class UUnlockDurationReward : public UUnlockReward {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStageDuration* Duration;
    
    UUnlockDurationReward();
};
