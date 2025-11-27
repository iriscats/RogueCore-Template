#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "DamageData.h"
#include "EnemyDeepPathfinderCharacter.h"
#include "AFlyingBug.generated.h"

class AActor;
class UAudioComponent;
class UDamageTag;
class UEnemyComponent;
class UFrozenPawnImpactComponent;
class UHealthComponent;
class UHealthComponentBase;
class UHitReactionComponent;
class UOutlineComponent;
class UPawnAlertComponent;
class UAIPerceptionComponent;
class UPawnStatsComponent;
class USoundBase;
class USphereComponent;
UCLASS(Blueprintable)
class AAFlyingBug : public AEnemyDeepPathfinderCharacter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemyComponent* EnemyComponent;
    
    UPawnStatsComponent* PawnStats;
    UOutlineComponent* Outline;
    UAIPerceptionComponent* Senses;
    UPawnAlertComponent* Alert;
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Instanced, meta=(AllowPrivateAccess=true))
    USphereComponent* ExplosionSphere;
    UAudioComponent* WingSoundComponent;
    UFrozenPawnImpactComponent* FrozenImpact;
    UHitReactionComponent* HitReactions;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    AActor* RotateTarget;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* ChatterSound;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_AttackStance, meta=(AllowPrivateAccess=true))
    bool AttackStance;
 
    float DistanceForAttackMode;
    float MinChatterDelay;
    float MaxChatterDelay;
    float AttackModeRotationSpeed;
    bool UsesAttackStance;
    bool SetLifeTime;
    bool LookStraight;
    bool UseDefaultRagdoll;
    AAFlyingBug(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartFizzle();
    UFUNCTION(BlueprintCallable)
    void SetRotateTarget(AActor* aTarget);
    void SetExternallyControlled(bool isExternallyControlled);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetAttackStance(bool isAttackStance);
    void PlayVoice();
    void OnStartFalling();
    UFUNCTION()
    void OnRep_AttackStance();
    void OnRagdoll();
    void OnFreezeImpact();
    void OnBugDeath(UHealthComponentBase* Health);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMidZpointFromCielingAndFloor(float& distanceFromCieling, float& distanceFromFloor) const;
    bool GetIsInAttackStance() const;
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_Ragdoll(const FVector_NetQuantize& Location, const FVector_NetQuantize& Impulse, uint8 BoneIndex);
    void AlertNearbyEnemies();
    void AddImpulseAndRagdoll(UHealthComponent* Health, float damageAmount, const FDamageData& DamageData, const TArray<UDamageTag*>& DamageTags);
};
