#pragma once
#include "CoreMinimal.h"
#include "Reward.h"
#include "AccessConditionReward.generated.h"

class UAccessCondition;
UCLASS(Blueprintable, EditInlineNew)
class UAccessConditionReward : public UReward {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAccessCondition* AccessCondition;
    
    UAccessConditionReward();
};
