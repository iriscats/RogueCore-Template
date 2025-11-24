#pragma once
#include "CoreMinimal.h"
#include "UnlockReward.h"
#include "UnlockComplexityReward.generated.h"

class UStageComplexity;
UCLASS(Blueprintable, EditInlineNew)
class UUnlockComplexityReward : public UUnlockReward {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStageComplexity* Complexity;
    
    UUnlockComplexityReward();
};
