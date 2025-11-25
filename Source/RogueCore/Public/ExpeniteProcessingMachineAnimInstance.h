#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ExpeniteProcessingMachineAnimInstance.generated.h"

class UCurveVector;
UCLASS(Blueprintable, NonTransient)
class UExpeniteProcessingMachineAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExpenitePotZOffset;
    
    float ExpenitePotScale;
    UCurveVector* ShrinkCurve;
    bool ShouldStartShrinking;
    UExpeniteProcessingMachineAnimInstance();
    UFUNCTION(BlueprintCallable)
    void SetMaxTime(const float Time);
};
