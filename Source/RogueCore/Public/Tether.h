#pragma once
#include "CoreMinimal.h"
#include "CarriableItem.h"
#include "NiagaraComponent.h"
#include "Tether.generated.h"

class UCarriableComponent;
class UDamageComponent;
class UFXSystemAsset;
class UInstantUsable;
class USkeletalMeshComponent;
class USoundCue;
class USphereComponent;
UCLASS(Blueprintable)
class ROGUECORE_API ATether : public ACarriableItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* BaseMesh;
    
    UInstantUsable* UsableComponent;
    UCarriableComponent* Carry;
    USphereComponent* UseTrigger;
    UNiagaraComponent* TetherBeam;
    USphereComponent* PysicalCollision;
    UDamageComponent* ExplosionDamage;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFXSystemAsset* ExplosionParticle;
    USoundCue* ExplosionSound;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool IsOnGround;
    float KnockBackForce;
    ATether(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetIsOnGround(bool NewIsOnGround);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDronePickup();
    void OnDroneDrop();
    void OnClosed();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void Explode();
    UFUNCTION(BlueprintCallable)
    UNiagaraComponent* DuplicateTetherBeam();
};
