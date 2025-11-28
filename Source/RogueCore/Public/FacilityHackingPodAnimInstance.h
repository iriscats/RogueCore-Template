#pragma once
#include "CoreMinimal.h"

#include "Animation/AnimInstance.h"
#include "EHackingPodState.h"
#include "FacilityHackingPodAnimInstance.generated.h"

class AActor;
UCLASS(Blueprintable, NonTransient)
class UFacilityHackingPodAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* SaluteTarget;
    
    FRotator LookingDirection;
    FRotator TargetRotation;
    bool IsHacking;
    EHackingPodState PodState;
    float RadarDishAngle;
    UFacilityHackingPodAnimInstance();
    UFUNCTION(BlueprintCallable)
    void SetSaluter(AActor* salutingTarget);
    void ResetSaluteTarget();
};
