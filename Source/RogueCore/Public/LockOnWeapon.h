#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "AmmoDrivenWeapon.h"
#include "LockCounter.h"
#include "Templates/SubclassOf.h"
#include "TracerData.h"
#include "LockOnWeapon.generated.h"

class AActor;
class ALockOnBeam;
class UActorTrackingWidget;
class UDamageComponent;
class UHitscanComponent;
class UStatusEffect;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API ALockOnWeapon : public AAmmoDrivenWeapon {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMaxTargetsDelegate, int32, InMaxTargets);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLockonTargetRotationUpdated, bool, hasTargetLockon, FRotator, socketRotation);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLockOnRifleLockingOnState);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLockOnCountDelegate, int32, InCurrentCount);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLockOnRifleLockingOnState OnLockingStarted;
    FLockOnRifleLockingOnState OnLockingStopped;
    FMaxTargetsDelegate OnMaxTargetsChanged;
    FLockOnCountDelegate OnLockOnCountChanged;
    FLockonTargetRotationUpdated OnLockonTargetRotationUpdated;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* AimTarget;
    float LockOnDamageMultiplier;
    int32 ShotsPerTarget;
    int32 MaxTargets;
    float TimeBetweenLockedShots;
    float LockOnTime;
    float MaxLockOnDegree;
    float LoseLockOnDegree;
    float DegreeTolerance;
    float MaxLockOnRange;
    bool bPrioritizeLowHitPoint;
    bool bAlwaysHitTarget;
    float MaxLockOnDuration;
    bool bLockOnControlsSentryGun;
    bool bSentryGunShootsOnLockedShot;
    TSubclassOf<UActorTrackingWidget> TrackingWidgetClass;
    TSubclassOf<ALockOnBeam> LockOnBeamClass;
    TSubclassOf<AActor> AoeActorClass;
    int32 AoeHitCountThreshhold;
    bool UseLockOnTargetStatusEffect;
    TSubclassOf<UStatusEffect> LockOnTargetStatusEffect;
    int32 PushStatusEffectEveryXLock;
    int32 LockOnCount;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UDamageComponent* DamageComponent;
    UHitscanComponent* HitscanComponent;
    FTracerData ChargedShotTracer;
    float ChargeSpeed;
    float SlowMovementAtCharge;
    bool FearEnabled;
    float FearFactorBase;
    float FearFactorPerShotBonus;
    float FearRange;
    float FearRangePerShotBonus;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool IsMovementSlowed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool Charging;
    float ChargeProgress;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool LastShotWasLockedOn;
    float LockOnRecoilMult;
    ALockOnWeapon(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UpdateRifleEye();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetMuzzleDirection(FVector TargetLocation);
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_TriggerAoe(FVector Location);
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_SetTotalLockCount(int32 totalLockCount);
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_SetLockCount(const FLockCounter& LockCounter);
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_SetIsMovementSlowed(bool bisMovementSlowed);
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_SetIsLatestShotLockedOn(bool bisShotLockedOn);
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_SetIsChargingShot(bool bisCharging);
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_PushStatusEffect(AActor* Target);
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_PopStatusEffect(AActor* Target);
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void Server_FiringComplete(int32 ShotsFired);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void RefundAmmo();
    UFUNCTION()
    void OnRep_AimTarget();
    void OnMovementSlowed(bool isSlowed);
    void OnHitDeadTarget();
    void OnHit(const FHitResult& Hit, bool AlwaysPenetrate);
    void OnAsyncFireComplete();
    void MuzzleLerpToTarget(FVector TargetLocation);
};
