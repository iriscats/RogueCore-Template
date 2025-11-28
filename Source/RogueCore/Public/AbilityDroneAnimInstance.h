#pragma once
#include "CoreMinimal.h"

#include "Animation/AnimInstance.h"
#include "AbilityDroneAnimInstance.generated.h"

class ADeepPathfinderCharacter;
UCLASS(Blueprintable, NonTransient)
class UAbilityDroneAnimInstance : public UAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector2D AngularVelocity;
    
    TWeakObjectPtr<ADeepPathfinderCharacter> Owner;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VelocityLerpSpeed;
    float HorizontalVelocityMultiplier;
    float VerticalVelocityMultiplier;
    UAbilityDroneAnimInstance();
};
