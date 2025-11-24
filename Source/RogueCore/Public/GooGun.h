#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "EGooGunFireMode.h"
#include "GooGun.generated.h"

class UAnimMontage;
class UFXSystemComponent;
class UNiagaraSystem;
class USoundBase;
UCLASS(Abstract, Blueprintable, NoExport)
class AGooGun : public AAmmoDrivenWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))

    UFXSystemComponent* ChargeupParticleInstance;

    UAnimMontage* FP_ChargeupMontage;

    UAnimMontage* TP_ChargeupMontage;

    AGooGun(const FObjectInitializer& ObjectInitializer);



public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FChargingDelegate);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FChargeChangedDelegate, float, charge);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FChargingDelegate OnStartCharging;
    FChargingDelegate OnEndCharging;
    FChargingDelegate OnChargingFailed;
    FChargeChangedDelegate OnChargeChanged;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChargeTime;
    int32 ShotCostCharged;
    float ChargeThreshold;
    float AutoStopCharingAfterSeconds;
    int32 ShotCostCycle;
    EGooGunFireMode FireMode;
    USoundBase* FullyChargedFireSound;
    int32 ChargedShotCount;
    float BuckShotSpreadV;
    float BuckShotSpreadH;
    float BuckshotArcCompensation;
    UNiagaraSystem* ChargeupParticles;
    UNiagaraSystem* ChargeupFireMuzzleFlash;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFXSystemComponent* ChargeupParticleInstance;
    UAnimMontage* FP_ChargeupMontage;
    UAnimMontage* TP_ChargeupMontage;
    AGooGun(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPuddleSuckedIn();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetOverChargeProgress() const;
    bool GetIsCharging();
    float GetChargeProgress() const;
};
