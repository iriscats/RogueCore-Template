#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DamageNumberStackingRules.h"
#include "EUpdateDamageNumberColor.h"
#include "ProjectileBase.h"
#include "ProjectileState.h"
#include "StackingDamageNumberSource.h"
#include "Templates/SubclassOf.h"
#include "Projectile.generated.h"

class AActor;
class APawn;
class AProjectile;
class UFSDPhysicalMaterial;
class UFSDProjectileMovementComponent;
class UObject;
class UPawnStat;
class UPrimitiveComponent;
class USceneComponent;
UCLASS(Abstract, Blueprintable)
class AProjectile : public AProjectileBase, public IStackingDamageNumberSource {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPawnStat* GravityModifier;
    
    UPawnStat* VelocityModifier;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    FProjectileState State;
    bool UseArmorDamageBoneCheck;
    TArray<TSubclassOf<AActor>> IgnoreActorClasses;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFSDProjectileMovementComponent* MovementComponent;
    FDamageNumberStackingRules DamageNumbersRules;
    bool CallPenetrateOnOverlap;
    bool CallImpactOnInTerrain;
    AProjectile(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    AProjectileBase* SpawnProjectileFromSelf(UObject* WorldContextObject, TSubclassOf<AProjectileBase> ProjectileClass, FVector Origin, FRotator velocityDirection);
    static AProjectileBase* SpawnProjectile(UObject* WorldContextObject, TSubclassOf<AProjectileBase> ProjectileClass, APawn* projectileOwner, FVector Origin, FRotator velocityDirection);
    static AProjectileBase* SpawnBallisticProjectile(UObject* WorldContextObject, TSubclassOf<AProjectile> ProjectileClass, APawn* projectileOwner, FVector Origin, FVector Velocity);
    UFUNCTION(BlueprintCallable)
    void SetHomingTargetComponent(USceneComponent* HomingTargetComponent, float Delay);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_DisableHoming();
    UFUNCTION()
    void OnRep_State(const FProjectileState& oldState);
    void OnPenetration(const FHitResult& HitResult);
    void OnImpact(const FHitResult& HitResult);
    void OnBounce(const FHitResult& ImpactResult, const FVector& ImpactVelocity);
    void OnBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool fromSweep, const FHitResult& SweepResult);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UFSDPhysicalMaterial* FindBoneIndexFromArmor(const FHitResult& HitResult, int32& outBoneIndex) const;
    // Fix for true pure virtual functions not being implemented
    float GetStackingTimeLimit() const override PURE_VIRTUAL(GetStackingTimeLimit, return 0.0f;);
    int32 GetMaxCombinationsPerentry() const override PURE_VIRTUAL(GetMaxCombinationsPerentry, return 0;);
    EUpdateDamageNumberColor GetColorBehaviour() const override PURE_VIRTUAL(GetColorBehaviour, return EUpdateDamageNumberColor::ENormal;);
};
