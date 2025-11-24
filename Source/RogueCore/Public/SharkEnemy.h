#pragma once
#include "CoreMinimal.h"

#include "Engine/NetSerialization.h"
#include "DamageData.h"
#include "ESharkEnemyState.h"
#include "EnemyDeepPathfinderCharacter.h"
#include "SharkEnemy.generated.h"

class AActor;
class APawn;
class UDamageComponent;
class UDamageTag;
class UEnemyComponent;
class UFXSystemAsset;
class UFakeMoverSettings;
class UFakePhysGrabberComponent;
class UHealthComponent;
class UHealthComponentBase;
class UInDangerComponent;
class UNiagaraComponent;
class UPrimitiveComponent;
class USoundCue;
class USphereComponent;
UCLASS(Abstract, Blueprintable, NoExport)
class ASharkEnemy : public AEnemyDeepPathfinderCharacter {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))

    ESharkEnemyState State;

    ASharkEnemy(const FObjectInitializer& ObjectInitializer);



public:
    USphereComponent* CollisionSphere;
    USphereComponent* NearTargetSphere;
    UNiagaraComponent* AirParticles;
    UNiagaraComponent* GroundParticles;
    UInDangerComponent* Danger;
    UEnemyComponent* EnemyComponent;
    UDamageComponent* Damage;
    UDamageComponent* BumpDamage;
    UFakePhysGrabberComponent* RestrictedGrabberComponent;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* ImpactCue;
    USoundCue* JumpSound;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_DiveTime, meta=(AllowPrivateAccess=true))
    float DiveForSeconds;
    float LaunchPower;
    float GrabTime;
    float RagdollSpeedFactor;
    float UpsideDownTime;
    float TiltOutSpeed;
    float SafeTimeAfterVounerable;
    float RaiseHeight;
    float AttackDuration;
    float ChanceToGrab;
    float MinTimeBetweenBumps;
    float ChanceForJump;
    float MinJumpCooldown;
    float MaxJumpCooldown;
    float JumpForce;
    float NormalHeight;
    float DiveHeight;
    float MinCirclingTime;
    float MaxCirclingTime;
    UFakeMoverSettings* CircleSetttings;
    UFakeMoverSettings* AttackSettings;
    UFakeMoverSettings* PostHitSettings;
    UFakeMoverSettings* JumpSettings;
    UFakeMoverSettings* VulnerableSettings;
    float MaxInGroundTime;
    float MinInGroundTime;
    float StartParticleTime;
    float EndParticleTime;
    UFXSystemAsset* DiveParticles;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    ESharkEnemyState State;
    ASharkEnemy(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetVulnerable();
    void ReleasePlayer(AActor* playerchar, bool fullGrabElapsed);
    void PopRecentlyBumpedPlayer();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStateChangedEvent(ESharkEnemyState CurrentState);
    void OnSeePawn(APawn* aPawn);
    UFUNCTION()
    void OnRep_State(ESharkEnemyState oldState);
    UFUNCTION()
    void OnRep_DiveTime();
    void OnNearTarget(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    void OnLandedEvent();
    void OnJumpEvent();
    void OnHit(float HitDamage, const FDamageData& DamageData, bool anyHealthLost, UHealthComponentBase* InHealthComponent);
    void OnExitState(ESharkEnemyState NewState);
    void OnEnterState(ESharkEnemyState NewState);
private:
    void OnDeathDetailed(UHealthComponent* aHealthComponent, float damageAmount, const FDamageData& DamageData, const TArray<UDamageTag*>& dTags);
    void OnCollided(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void Jumped();
    void ImpactSound();
    void DiveShow();
    void DiveHide();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_DoRagdollImpact(const FVector_NetQuantize& Direction);
    void ActivateDanger();
};
