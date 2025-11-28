#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "EUpdateDamageNumberColor.h"
#include "HitscanWeapon.h"
#include "StackingDamageNumberSource.h"
#include "Templates/SubclassOf.h"
#include "AutoCannon.generated.h"

class UAnimMontage;
class UStatusEffect;
UCLASS(Abstract, Blueprintable)
class AAutoCannon : public AHitscanWeapon, public IStackingDamageNumberSource {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StartingFireRate;
    
    float MaxFireRate;
    FRuntimeFloatCurve FireRateCurve;
    float FireTimeReductionScale;
    float FireTimeIncreaseScale;
    float MaxFireTimeCap;
    float DamageBonusAtFullROF;
    bool StatusEffectAtFullROF;
    float FireTimeOffsetForMaxRateOfFireBonus;
    float StartLoopingSoundAt;
    TSubclassOf<UStatusEffect> StatusAtFullROF;
    UAnimMontage* WPN_Fire_2;
    float CurrentFireTime;
    AAutoCannon(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetStatusActive(bool IsActive);
    // Fix for true pure virtual functions not being implemented
    UFUNCTION(BlueprintCallable)
    float GetStackingTimeLimit() const override PURE_VIRTUAL(GetStackingTimeLimit, return 0.0f;);
    int32 GetMaxCombinationsPerentry() const override PURE_VIRTUAL(GetMaxCombinationsPerentry, return 0;);
    EUpdateDamageNumberColor GetColorBehaviour() const override PURE_VIRTUAL(GetColorBehaviour, return EUpdateDamageNumberColor::ENormal;);
};
