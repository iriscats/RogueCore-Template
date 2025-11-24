#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EInputKeys.h"
#include "DetPack.generated.h"

class ADetPackItem;
class APlayerCharacter;
class UExplosionComponent;
class UHealthComponentBase;
class UProjectileMovementComponent;
class USimpleHealthComponent;
class USingleUsableComponent;
UCLASS(Blueprintable, NoExport)
class ADetPack : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpgradedStaggerChance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    float VisualDamageRadius;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float IncreasedFearRadius;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProjectileMovementComponent* Movement;
    UExplosionComponent* Explosion;
    USingleUsableComponent* UseComp;
    USimpleHealthComponent* SimpleHealth;
    ADetPackItem* Detonator;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_HasExploded, meta=(AllowPrivateAccess=true))
    bool HasExploded;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsMoving, meta=(AllowPrivateAccess=true))
    bool IsMoving;

protected:
    float UpgradedStaggerDuration;
    float UpgradedFearFactor;
    float IncreasedStaggerRadius;
    bool ExplodesOnDeath;
    bool HasExtraStaggerRadius;
    bool HasExtraFearRadius;
    ADetPack(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UseFearStaggerUpgrades();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void RecieveHitObject();
    UFUNCTION()
    void OnRep_IsMoving();
    UFUNCTION()
    void OnRep_HasExploded();
    void OnExploded();
    void OnDetPackPickedUp(APlayerCharacter* User, EInputKeys Key);
    void OnDetPackDeath(UHealthComponentBase* HealthComponent);
};
