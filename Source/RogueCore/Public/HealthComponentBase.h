#pragma once
#include "CoreMinimal.h"

#include "Components/ActorComponent.h"
#include "BodypartHitSigDelegate.h"
#include "DamageRelevant.h"
#include "DamageSigDelegate.h"
#include "DeathSigDelegate.h"
#include "EHealthbarType.h"
#include "Health.h"
#include "HealthChangedSigDelegate.h"
#include "HitSigDelegate.h"
#include "OnHitByHitScanDelegate.h"
#include "OnRadialDamageDelegate.h"
#include "HealthComponentBase.generated.h"

class AActor;
class UDamageClass;
class UFXSystemAsset;
class UPrimitiveComponent;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UHealthComponentBase : public UActorComponent, public IHealth, public IDamageRelevant {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCanTakeDamageDelegate, bool, OutCanTakeDamage);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHealthChangedSig OnHealthChanged;
    FDamageSig OnDamageHealed;
    FDamageSig OnDamageTaken;
    FHitSig OnHit;
    FBodypartHitSig OnBodypartHit;
    FDeathSig OnDeath;
    FOnRadialDamage OnRadialDamage;
    FOnHitByHitScan OnHitByHitScan;
    FCanTakeDamageDelegate OnCanTakeDamageChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShowLaserPointMarkerWhenDead;
    bool canTakeDamage;
    bool PassthroughTemperatureDamage;
    UHealthComponentBase(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TrySetCanTakeDamage(bool NewCanTakeDamage);
    void TakeDamageSimple(float damageAmount, AActor* DamageCauser, int32 CritLevel, UDamageClass* DamageClass);
    void SetHealthDirectly(float newHealthValue);
    void SetCanTakeDamageIsLocked(bool IsLocked);
    void SetCanTakeDamage(bool NewCanTakeDamage);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void Kill(AActor* DamageCauser);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDead() const;
    bool IsAlive() const;
    float Heal(float amount);
    bool GetShowHealthBar() const;
    float GetHealthPct() const;
    TScriptInterface<IHealth> GetHealthComponentForCollider(UPrimitiveComponent* Primitive) const;
    FVector GetHealthBarWorldOffset() const;
    float GetHealth() const;
    UFXSystemAsset* GetGenericImpactParticles() const;
    bool GetCanTakeDamage() const;
    bool CanTakeDamageFrom(UDamageClass* DamageClass) const;
    // Fix for true pure virtual functions not being implemented
    virtual AActor* GetOwner() const override PURE_VIRTUAL(GetOwner, return NULL;);
    virtual float GetMaxHealth() const override PURE_VIRTUAL(GetMaxHealth, return 0.0f;);
    virtual EHealthbarType GetHealthbarType() const override PURE_VIRTUAL(GetHealthbarType, return EHealthbarType::None;);
};
