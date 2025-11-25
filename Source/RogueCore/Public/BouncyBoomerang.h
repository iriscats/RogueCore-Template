#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BoomerangMover.h"
#include "BoomerangSyncer.h"
#include "EBoomerangState.h"
#include "Grenade.h"
#include "Templates/SubclassOf.h"
#include "BouncyBoomerang.generated.h"

class AFSDPawn;
class UDamageAsset;
class UFXSystemAsset;
class UNiagaraSystem;
class USceneComponent;
class USoundCue;
class UStatusEffect;
UCLASS(Blueprintable, NoExport)
class ABouncyBoomerang : public AGrenade {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* Root;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageAsset* Damage;
    int32 BouncesLeft;
    float ConeRange;
    float ConeWidth;
    float BounceRange;
    float ToTargetSpeed;
    float TurnToTargetSpeed;
    float PathToDistPercent;
    FVector DefaultLocalBounceVector;
    FVector BounceVectorRandomness;
    float InitialBounceVectorCof;
    float ArcTimeScale;
    float GoBackAcceleration;
    float GoBackHardness;
    float TerrainCheckUpdateRate;
    float HitEnemyRange;
    float HitPlayerRange;
    float CatchSoundRange;
    float HitTerrainRange;
    FVector CatchLocationOffset;
    TArray<TSubclassOf<UStatusEffect>> OnDamageStatusEffects;
    UNiagaraSystem* EnemyHitNiagaraSystem;
    UFXSystemAsset* EnemyHitParticleSystem;
    USoundCue* ImpactSound;
    USoundCue* ReturnCatchSound;
    USoundCue* ThrowBoomerangSound;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* MeshPivot;
    USceneComponent* YawPivot;
    float MeshRotationRate;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_TargetEnemy, meta=(AllowPrivateAccess=true))
    AFSDPawn* TargetEnemy;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    AFSDPawn* PredictedNextEnemy;
    UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_RandomSeed, meta=(AllowPrivateAccess=true))
    uint32 RandomSeed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EBoomerangState State;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_PosVel, meta=(AllowPrivateAccess=true))
    FBoomerangSyncer PosVel;
    FBoomerangMover Mover;
    ABouncyBoomerang(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_TargetEnemy(AFSDPawn* lastEnemy);
    UFUNCTION()
    void OnRep_State();
    UFUNCTION()
    void OnRep_RandomSeed();
    UFUNCTION()
    void OnRep_PosVel();
    void CheckIfCollidingWithTerrain();
};
