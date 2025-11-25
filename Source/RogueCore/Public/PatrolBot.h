#pragma once
#include "CoreMinimal.h"

#include "Curves/CurveFloat.h"
#include "EDeepMovementState.h"
#include "EPatrolBotControlState.h"
#include "EPatrolBotState.h"
#include "EnemyDeepPathfinderCharacter.h"
#include "PatrolBot.generated.h"

class AActor;
class UAudioComponent;
class UAvoidCeilingComponent;
class UDamageComponent;
class UEnemyComponent;
class UFakeMoverSettings;
class UHackingUsableComponent;
class UNiagaraComponent;
class UParticleSystemComponent;
class UPawnAlertComponent;
class UPlayerImpactCooldownComponent;
class UPrimitiveComponent;
class UProjectileAttackComponent;
class USoundCue;
class USphereComponent;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API APatrolBot : public AEnemyDeepPathfinderCharacter {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHackingUsableComponent* HackingUsable;

    USphereComponent* CollisionSphere;
    USphereComponent* NearTargetSphere;
    UParticleSystemComponent* LaserBeam;
    UParticleSystemComponent* TearingGroundParticles;
    UNiagaraComponent* LaserBeamNS;
    UNiagaraComponent* TearingGroundParticlesNS;
    UEnemyComponent* EnemyComponent;
    UDamageComponent* Damage;
    UDamageComponent* BumpDamage;
    UPawnAlertComponent* Alert;
    UPlayerImpactCooldownComponent* ImpactCooldown;
    UAvoidCeilingComponent* CeilingAvoidance;
    UAudioComponent* RollingAudio;
    UAudioComponent* FlyingAudio;
    UProjectileAttackComponent* RollingRangedAttack;
    UProjectileAttackComponent* FlyingRangedAttack;
    UProjectileAttackComponent* MissileAttack;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxMotionSoundVelThresholdFlying;
    float MaxMotionSoundVelThreshold;
    float MaxTurningMotionSoundVelThreshold;
    bool DebugAudio;
    float HackedAttackMultiplier;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsLockedOn, meta=(AllowPrivateAccess=true))
    bool IsLockedOn;
    float DelayAfterLockOn;
    USoundCue* ImpactCue;
    USoundCue* JumpSound;
    USoundCue* StartupAccelerationSound;
    float LaunchPower;
    float SpawnRocketsTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EPatrolBotState State;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ControlState, meta=(AllowPrivateAccess=true))
    EPatrolBotControlState ControlState;
    float HackedAttackSpeedMultiplier;
    float LaserPenetrationDistance;
    float MinTurretAngle;
    float MaxTurretAngle;
    float SpawnRocketsChance;
    float GunRange;
    float RollingAttackCooldown;
    float FlyingAttackCooldown;
    float TurretLerpSpeed;
    float AimDownwardsOffset;
    float AccelerationThreshold;
    float LowSpeedThreshold;
    FRuntimeFloatCurve SpeedTiltCurve;
    UFakeMoverSettings* RollSettings;
    UFakeMoverSettings* JumpSettings;
    UFakeMoverSettings* SpawnRocketsSettings;
    bool CanJump;
    float JumpForce;
    float StartFlyingTimer;
    float MinRollingTime;
    float MaxRollingTime;
    float MinFlyingTime;
    float MaxFlyingTime;
    float SinSpeed;
    float SinSize;
    float FlyingDampOmega;
    float RollingDampOmega;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_FiringRockets, meta=(AllowPrivateAccess=true))
    bool FiringRockets;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool Alerted;
 
    AActor* CurrentTarget;
    APatrolBot(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetIsPatrolling(bool patroling);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetHacked();
    void SetFiringRockets(bool firing);
    void ReviveDrone();
 
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStateChangedEvent(EPatrolBotState CurrentState);
public:
    void OnSpawnRocketsEvent();
    void OnRocketsEnded();
    void OnRevived();
    UFUNCTION()
    void OnRep_State();
    UFUNCTION()
    void OnRep_IsLockedOn();
    UFUNCTION()
    void OnRep_FiringRockets();
    UFUNCTION()
    void OnRep_ControlState(EPatrolBotControlState oldState);
    void OnProjectileSpawned();
    void OnMovementStateChanged(EDeepMovementState NewState);
    void OnLockedOn();
    void OnLandedEvent();
    void OnJumpEvent();
    void OnFireRockets();
    void OnDroneHacked();
    void OnDroneAlerted();
    void OnDisabled();
    void OnControlStateChanged(EPatrolBotControlState NewControlState);
    void OnCollided(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void Jumped();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsHacked() const;
    UFUNCTION(NetMulticast, Unreliable)
    void ImpactSound();
    void EndFireRockets();
    void DisableDrone();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_SetLaserBeamActive(bool Active);
};
