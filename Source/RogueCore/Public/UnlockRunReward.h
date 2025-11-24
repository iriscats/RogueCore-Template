#pragma once
#include "CoreMinimal.h"
#include "Reward.h"
#include "UnlockRunReward.generated.h"

class URunTemplate;
UCLASS(Blueprintable, EditInlineNew)
class UUnlockRunReward : public UReward {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    URunTemplate* Run;
    
    UUnlockRunReward();
};
