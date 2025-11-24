#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EMiningPodRampState.h"
#include "EMiningPodState.h"
#include "MiningPodAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UMiningPodAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMiningPodRampState rampState;
    
    EMiningPodState PodState;
    UMiningPodAnimInstance();
};
