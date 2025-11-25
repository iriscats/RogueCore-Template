#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "ChargeChangedSignatureDelegate.h"
#include "ChargedWeapon.generated.h"

class UAnimMontage;
class UFXSystemAsset;
class UFXSystemComponent;
class UNiagaraSystem;
class USoundBase;
UCLASS(Abstract, Blueprintable)
class AChargedWeapon : public AAmmoDrivenWeapon {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FChargeChangedSignature OnChargeChanged;
    
    FChargeChangedSignature OnHeatChanged;
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* FP_OverheatAnim;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFXSystemComponent* ChargeupParticleInstance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundBase* NormalFiresound;
    UAnimMontage* WeaponOverheatAnim;
    UAnimMontage* FP_ChargeupMontage;
    UAnimMontage* TP_ChargeupMontage;
    UFXSystemAsset* ChargeupParticles;
    UNiagaraSystem* ChargeupFireMuzzleFlash;
    USoundBase* FullyChargedFireSound;
    float ChargeSpeed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Charging, meta=(AllowPrivateAccess=true))
    bool Charging;
    float ChargeProgress;
    int32 ShotCostAtBelowFullCharge;
    int32 ShotCostAtFullCharge;
    bool ChargedShotsOnly;
    float ChargeShotAllowedAfterProgress;
    bool AutoFireWhenOverheated;
    float TotalHeat;
    float CoolingRate;
    float HeatPerSecondWhileCharging;
    float HeatPerSecondWhenCharged;
    float HeatPerNormalShot;
    float HeatPerChargedShot;
    AChargedWeapon(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetOverheated(bool IsOverheated);
    void SetChargeSpeedMultiplier(float Value);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetIsCharging(bool isCharging);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RecieveStoppedCharging(float NewChargeProgress);
    void RecieveStartedCharging();
    void RecieveChargeProgressChanged(float NewChargeProgress);
    void ReceiveOverheatedChanged(bool IsOverheated);
    UFUNCTION()
    void OnRep_Charging();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsCharging() const;
};
