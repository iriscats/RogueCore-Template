#pragma once
#include "CoreMinimal.h"


#include "ECrossbowEffectApplication.h"
#include "OnCrossbowDamageDealtDelegate.h"
#include "Projectile.h"
#include "Templates/SubclassOf.h"
#include "CrossbowProjectileBase.generated.h"


class ACrossbowProjectileStuck;
class UCrossbowProjectileMagnetic;
class UCrossbowProjectileRicochet;
class UCrossbowStuckProjectileEffectBanshee;
class UDamageComponent;
class UNiagaraComponent;
class URecallableProjectileComponent;
class USoundCue;
class UStaticMesh;
class UStatusEffect;
class UTexture2D;
UCLASS(Blueprintable)
class ACrossbowProjectileBase : public AProjectile {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnCrossbowDamageDealt OnDamageDealt;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StatusEffectTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_BansheePulseActive, meta=(AllowPrivateAccess=true))
    bool BansheePulseActive;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCrossbowProjectileMagnetic* MagneticComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_OnlyTrailShown, meta=(AllowPrivateAccess=true))
    bool OnlyTrailShown;
 
    UCrossbowProjectileRicochet* RicochetComponent;
    UCrossbowStuckProjectileEffectBanshee* BansheeComponent;
    UNiagaraComponent* BansheePulseComponent;
    TSubclassOf<UCrossbowStuckProjectileEffectBanshee> BansheeComponentClass;
    TSubclassOf<URecallableProjectileComponent> RecallComponentClass;
    TSoftObjectPtr<UTexture2D> Icon;
    TSoftObjectPtr<UTexture2D> TriforkIcon;
    TSubclassOf<ACrossbowProjectileStuck> SpawnableStuckProjectile;
    TSubclassOf<UStatusEffect> OnDamageEffect;
    ECrossbowEffectApplication EffectApplication;
    uint8 SelectionPriority;
    bool CanEverBePickedUp;
    bool Penetrates;
    USoundCue* ImpactSound;
    bool IsASpecialProjectile;

    UDamageComponent* MainDamageComponent;
    UDamageComponent* SimpleDamageComponent;
    UStaticMesh* ProjectileMesh;
    float KillTrailAfterTime;
    ACrossbowProjectileBase(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetSimpleDamageComponentFromBP();
    UFUNCTION(BlueprintCallable)
    void SetSimpleDamageComponent(UDamageComponent* Component);
    void SetMainDamageComponentFromBP();
    void SetMainDamageComponent(UDamageComponent* Component);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_HandleImpact(const FHitResult& HitResult, const FVector& RelativeLocation);
    UFUNCTION()
    void OnRep_OnlyTrailShown();
    UFUNCTION()
    void OnRep_BansheePulseActive();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocallyControlled() const;
    bool GetSpecialArrowEquipped() const;
    float GetScaledStatusEffectTime() const;
    void ApplyDamageEffects(const FHitResult& HitResult, const FVector& RelativeLocation);
};
