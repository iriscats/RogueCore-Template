#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "EImpactDecalSize.h"
#include "ELineRotation.h"
#include "Projectile.h"
#include "ScaledEffect.h"
#include "Particles/ParticleSystemComponent.h"
#include "Components/SceneComponent.h"
#include "LineCutterProjectile.generated.h"

class UDamageComponent;
class UNiagaraComponent;
UCLASS(Blueprintable, NoExport)
class ALineCutterProjectile : public AProjectile {
    GENERATED_BODY()


public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPerformHit, const FHitResult&, Result);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLineLifeSpanDestroy);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FLineEffectHide);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLineDestroy, const FHitResult&, Result);
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FScaledEffect EletricHitEffect;
    FScaledEffect ProjectileDisappearEffect;
    float SwipeRadius;
    float DoubleLineDistanceMultiplier;
    float OverlapRadius;
    bool DestroyOnTerrainCollision;
    bool IsDead;
    bool bHasReversedDirection;
    float FlyStraighTime;
    EImpactDecalSize EletricDecalSize;
    EImpactDecalSize ImpactDecalSize;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLineDestroy OnLineDestroy;
    FLineLifeSpanDestroy OnLineLifespanEnd;
    FPerformHit OnPerformHit;
    FLineEffectHide OnLineEffectHide;
    FVector LeftLastPosition;
    FVector RightLastPosition;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* LineRoot;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* LeftSphere;
    USceneComponent* RightSphere;
    USceneComponent* LeftSphere2;
    USceneComponent* RightSphere2;
    USceneComponent* LeftSphere3;
    USceneComponent* RightSphere3;
    UParticleSystemComponent* BeamParticle;
    UParticleSystemComponent* BeamParticle2;
    UParticleSystemComponent* BeamParticle3;
    UNiagaraComponent* BeamParticle1NS;
    UNiagaraComponent* BeamParticle2NS;
    UNiagaraComponent* BeamParticle3NS;
    UParticleSystemComponent* LeftHitParticles;
    UParticleSystemComponent* RightHitParticles;
    UNiagaraComponent* LeftHitParticlesNS;
    UNiagaraComponent* RightHitParticlesNS;
    float RotationSpeed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_LineRotation, meta=(AllowPrivateAccess=true))
    FRotator LineRotation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    ELineRotation RotationMode;
    bool ShouldExplode;
    bool OnlyOne;
    bool IsDoubleLine;
    bool HasPlasmaTrail;
    float LineMaxSize;
    float LineExpansionDelay;
    float TimeToLineExpansion;
    float FireRate;
    UDamageComponent* DamageComponent;
    UDamageComponent* InitialDamageComponent;
    int32 InitialHitDamageMultiplier;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float InhibitImpactDecalsTime;
    float MinTimeBetweenImpactDecals;
    UDamageComponent* ExplosionDamageComponent;
    ALineCutterProjectile(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UpdateBeamLocations();
    void TerrainSweep(const FVector& Left, const FVector& Right);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartSpawningTrail();
    void SpawnDecal(FHitResult& Result);
    void SetExtraBeamVisibility(bool IsVisible);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_RemoveDebris(int32 instance, int32 Component);
    UFUNCTION()
    void OnRep_LineRotation();
    void Fire(const FVector& Origin, const FVector& Direction, float Distance);
};
