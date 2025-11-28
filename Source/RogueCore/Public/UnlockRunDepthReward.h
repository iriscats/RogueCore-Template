#pragma once
#include "CoreMinimal.h"
#include "ERunDepth.h"
#include "Reward.h"
#include "UnlockRunDepthReward.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UUnlockRunDepthReward : public UReward {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERunDepth RunDepth;
    
    UUnlockRunDepthReward();
};
