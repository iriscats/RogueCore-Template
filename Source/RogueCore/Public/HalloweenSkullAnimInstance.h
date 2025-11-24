#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "HalloweenSkullAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UHalloweenSkullAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float JawMovementSpeedMin;
    
    float JawMovementSpeedMax;
    float JawMovementRange;
    float SwitchAnimationTimeMin;
    float SwitchAnimationTimeMax;
    float JawPosition;
    UHalloweenSkullAnimInstance();
};
