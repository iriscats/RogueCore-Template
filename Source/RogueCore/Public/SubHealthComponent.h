#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageSigDelegate.h"
#include "EEnemyHealthScaling.h"
#include "EHealthbarType.h"
#include "Health.h"
#include "HealthChangedSigDelegate.h"
#include "SubHealthComponentDelegateDelegate.h"
#include "SubHealthComponent.generated.h"

class AActor;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USubHealthComponent : public UActorComponent, public IHealth {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDamageSig OnDamageTaken;
    
    FHealthChangedSig OnHealthChanged;
    FSubHealthComponentDelegate OnCanTakeDamageChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EHealthbarType HealthbarType;
    bool passthroughDamageWhenDisabled;
    EEnemyHealthScaling EnemyHealthScaling;
    USubHealthComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetPassthroughDamageWhenDisabled(bool NewPassthroughDamageWhenDisabled);
    void SetCanTakeDamage(bool canTakeDamage);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDead() const;
    bool IsAlive() const;
    float GetHealthPct() const;
    float GetHealth() const;
    bool GetCanTakeDamage() const;
    // Fix for true pure virtual functions not being implemented
    virtual AActor* GetOwner() const override PURE_VIRTUAL(GetOwner, return NULL;);
    virtual float GetMaxHealth() const override PURE_VIRTUAL(GetMaxHealth, return 0.0f;);
    virtual EHealthbarType GetHealthbarType() const override PURE_VIRTUAL(GetHealthbarType, return EHealthbarType::None;);
};
