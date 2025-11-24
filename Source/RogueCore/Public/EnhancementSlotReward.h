#pragma once
#include "CoreMinimal.h"
#include "Reward.h"
#include "EnhancementSlotReward.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UEnhancementSlotReward : public UReward {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 amount;
    
    UEnhancementSlotReward();
};
