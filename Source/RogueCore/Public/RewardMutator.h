#pragma once
#include "CoreMinimal.h"
#include "Mutator.h"
#include "RewardMutator.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URewardMutator : public UMutator {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText RewardText;
    
    float XPMultiplier;
    float CreditMultiplier;
    URewardMutator();
};
