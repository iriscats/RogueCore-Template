#pragma once
#include "CoreMinimal.h"

#include "HealthComponentBase.h"
#include "SimpleHealthComponent.generated.h"

class UDamageTag;
class UEnemyComponent;
class UPawnStat;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class USimpleHealthComponent : public UHealthComponentBase {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Damage, meta=(AllowPrivateAccess=true))
    float Damage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxHealth;
    bool InvulnerableToNonDefinedResistances;
    float EnvironmentalDamageResistance;
    bool bShowHealthBar;
    FVector HealthBarOffsetWorld;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UEnemyComponent> EnemyComponent;
    TMap<UPawnStat*, float> Resistances;
    TArray<UDamageTag*> RequiredDamageTags;
    bool AutomaticFlushNetDormancy;
    USimpleHealthComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_Damage(float oldDamage);
    float HealFromDeath(float amount);
};
