#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "BoltActionWeaponFullyFocusedDelegateDelegate.h"
#include "Templates/SubclassOf.h"
#include "TracerData.h"
#include "BoltActionWeapon.generated.h"

class AActor;
class UDamageComponent;
class UFSDPhysicalMaterial;
class UFXSystemAsset;
class UHealthComponentBase;
class UHitscanComponent;
class UPrimitiveComponent;
class USoundBase;
class USoundCue;
class UStatusEffect;
UCLASS(Abstract, Blueprintable, NoExport)
class ABoltActionWeapon : public AAmmoDrivenWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoltActionWeaponFullyFocusedDelegate FullyFocusedEvent;
    
    FBoltActionWeaponFullyFocusedDelegate FocusLostEvent;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UDamageComponent* DamageComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHitscanComponent* HitscanComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> FocusedHitSTE;
    bool RequireWeakspotForFocusedHitSTE;
    bool IsNoGravityOnFocusEnabled;
    float NoGravityOnFocusDuration;
    float NoGravityFocusFallFriction;
    float NoGravityFocusGravityScale;
    float ZoomSpreadAmount;
    float ZoomMinSpreadWhileMoving;
    float ChargeSpeed;
    float ChargeAmmoCost;
    float ChargeRecoilMult;
    USoundCue* ZoomedInAudio;
    UFXSystemAsset* ChargedShotTrailParticles;
    FTracerData ChargedShotTracer;
    USoundCue* ButtonDownFireSound;
    USoundBase* ChargedShotFireSound;
    float ChargedFoVChange;
    float ChargedFoVFadeSpeed;
    float MinCharge;
    float SlowMovementAtCharge;
    float FullChargeDamageBonus;
    float AimedShotStaggerChance;
    float AimedShotWeakpointDamageBonusMultiplier;
    float AimedWeakspotKilLRange;
    float TargetKilledReloadTimeBoost;
    float TargetKilledReloadTimeBoostDuration;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool LastShotWasAimed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool IsMovementSlowed;
    bool ChargeAffectsDamage;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool Charging;
    float ChargeProgress;
    ABoltActionWeapon(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetOverheated(bool IsOverheated);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetIsMovementSlowed(bool bisMovementSlowed);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetIsLatestShotFocused(bool bisShotFocused);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetIsChargingShot(bool bisCharging);
    void OnTimerElapsed();
    void OnTargetKilled(AActor* Target, UFSDPhysicalMaterial* PhysicalMaterial, bool wasDirectHit);
    void OnTargetDamaged(UHealthComponentBase* Health, float amount, UPrimitiveComponent* HitComponent, UFSDPhysicalMaterial* PhysicalMaterial);
    void OnShotPowerSet();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnMovementSlowed(bool isSlowed);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_OnTargetKilled(bool BoostReloadTime);
};
