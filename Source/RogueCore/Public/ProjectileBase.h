#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"

#include "Engine/NetSerialization.h"
#include "EOnProjectileImpactBehaviourEnum.h"
#include "OnProjectileImpactDelegateDelegate.h"
#include "PrefetchedData.h"
#include "ProjectileImpact.h"
#include "ProjectileBase.generated.h"

class AProjectileBase;
class UDamageAsset;
class UDamageComponent;
class UFSDPhysicalMaterial;
class UItemUpgrade;
class UPrimitiveComponent;
class UProjectileUpgradeElement;
class UShapeComponent;
class USoundCue;
class UTerrainMaterial;
UCLASS(Abstract, Blueprintable)
class AProjectileBase : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnProjectileImpactDelegate OnProjectileImpacted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ProjectileImpact, meta=(AllowPrivateAccess=true))
    FProjectileImpact ProjectileImpact;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageAsset* ImpactDamage;
 
    FPrefetchedData PrefetchedData;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UShapeComponent* CollisionComponent;
    USoundCue* WhizbySound;
    float LifeSpan;
    float VelocityMultiplier;
    float WhizByCooldown;
    float WhizByStartDistance;
    float GravityMultiplier;
    bool SeparateTerrainImpactCheck;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EOnProjectileImpactBehaviourEnum EOnImpactBehaviour;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool IsSpawnedFromWeapon;
    bool AffectedByDifficultySpeedModifier;
    bool SetInitialSpeedToMaxSpeed;
    bool AutoDisableCollisionOnImpact;
    bool Exploded;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool DoOnImpact;
    bool DoOnImpact2;
    bool DoOnImpact3;
    bool DoOnSpawnVar;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsDorment, meta=(AllowPrivateAccess=true))
    bool IsDorment;
    AProjectileBase(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTerrainMaterial* TryGetTerrainMaterial() const;
    UFUNCTION(BlueprintCallable)
    void StopMovement();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetState(FVector_NetQuantize position, FVector_NetQuantize Velocity);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_Penetrated(const FProjectileImpact& Impact);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_Impacted(const FProjectileImpact& Impact);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUpgradeElementAdded(UProjectileUpgradeElement* element);
    UFUNCTION()
    void OnRep_ProjectileImpact();
    UFUNCTION()
    void OnRep_IsDorment(const bool wasDorment);
    void OnPenetrated(bool PredictedPenetration, const FHitResult& HitResult);
    void OnInitialized();
    void OnImpacted(bool PredictedImpact, const FHitResult& HitResult);
    void MakeBouncy();
    void InitState(const FVector& ShootDirection, const FVector& initialBonusVelocity);
    void InitComponents();
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void IgnoreCollision(UPrimitiveComponent* otherCollider);
    bool HasImpactAuthority() const;
    float GetGameTimeSinceActivation() const;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    UDamageComponent* GetDamageComponent();
    int32 GetBoneIndex() const;
    void DoOnSpawn();
    static void DisableProjectileCollision(AProjectileBase* projectileA, AProjectileBase* projectileB);
    void DisableAndDestroy();
    UFSDPhysicalMaterial* DamageArmor(UDamageComponent* DamageComponent, const FHitResult& HitResult);
    void CustomEvent(const UItemUpgrade* Event);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_DrawServersDebugPath(FVector Location);
    void Activate(AActor* owningActor, FVector Origin, FVector_NetQuantizeNormal Direction, FVector_NetQuantizeNormal initialBonusVelocity);
};
