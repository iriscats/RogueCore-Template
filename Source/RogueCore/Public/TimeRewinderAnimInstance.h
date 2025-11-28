#pragma once
#include "CoreMinimal.h"

#include "Curves/CurveFloat.h"
#include "AbilityItemAnimInstance.h"
#include "RewinderKnobIdle.h"
#include "TimeRewinderAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UTimeRewinderAnimInstance : public UAbilityItemAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRewinderKnobIdle> KnobIdles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRotator SecondHandRotation;
    FRotator MinuteHandRotation;
    FRotator KnobRotation;
    FRuntimeFloatCurve ClockHandMovement;
    float AngleShift;
    float IdleAnimprogress;
    float MinKnobIdleCooldown;
    float MaxKnobIdleCooldown;
    bool RewindPointPlaced;
    bool IsMoving;
    UTimeRewinderAnimInstance();
    UFUNCTION(BlueprintCallable)
    void Tick();
    void OnUnequipped();
    void OnEquipped();
};
