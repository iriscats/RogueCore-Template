#pragma once
#include "CoreMinimal.h"
#include "EnemyAttacker.h"
#include "EnemyDeepPathfinderCharacter.h"
#include "SpiderEnemy.generated.h"

class AActor;
class UHitReactionComponent;
class UPawnStatsComponent;
class UStaticMesh;
class UStaticMeshComponent;
UCLASS(Blueprintable, NoExport)
class ASpiderEnemy : public AEnemyDeepPathfinderCharacter, public IEnemyAttacker {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPawnStatsComponent* PawnStats;
    
    UHitReactionComponent* HitReactions;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStaticMesh* GoreMesh;
    bool ApplyDifficultySpeedModifier;
    float AttackDamageModifier;
    bool LimitRagdollSpeed;
    float MaxRagdollSpeed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_LookAtTarget, meta=(AllowPrivateAccess=true))
    AActor* LookAtTarget;
    ASpiderEnemy(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetLookAtTarget(AActor* Target);
    UFUNCTION()
    void OnRep_LookAtTarget();
    UStaticMeshComponent* CreateHeadGore();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void AlertNearbyEnemies();
    // Fix for true pure virtual functions not being implemented
    float GetAttackDamageModifier() const override PURE_VIRTUAL(GetAttackDamageModifier, return 0.0f;);
};
