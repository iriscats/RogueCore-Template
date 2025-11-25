#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Curves/CurveFloat.h"
#include "AmmoRegenComponent.generated.h"

class AAmmoDrivenWeapon;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAmmoRegenComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve RegenIntervalCurve;
    
    TWeakObjectPtr<AAmmoDrivenWeapon> Weapon;
    float AmmoGeneratedFromOverHeat;
    float OverheatRechargeDelay;
    float OverheatRechargeEndTimeGap;
    float RechargeRateMultiplier;
    float RechargeDelay;
    float FullyDrainedRechargeDelay;
    float RechargeAmount;
    UAmmoRegenComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StartRecharge();
    void OnWeaponOverHeated();
    void OnWeaponFired();
};
