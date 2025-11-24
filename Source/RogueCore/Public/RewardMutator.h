#pragma once
#include "CoreMinimal.h"
#include "Mutator.h"
#include "RewardMutator.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URewardMutator : public UMutator {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText RewardText;
    
    float XPMultiplier;
    float CreditMultiplier;
    URewardMutator();
};
