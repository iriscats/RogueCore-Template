#pragma once
#include "CoreMinimal.h"
#include "Reward.h"
#include "ActivityCardReward.generated.h"

class UGameActivityType;
UCLASS(Blueprintable, EditInlineNew)
class UActivityCardReward : public UReward {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameActivityType* Activity;
    
    UActivityCardReward();
};
