#pragma once
#include "CoreMinimal.h"
#include "SubHealthComponent.h"
#include "DestructibleSubHealthComponent.generated.h"

class UDestructibleSubHealthComponent;
class USceneComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDestructibleSubHealthComponent : public USubHealthComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSubHealthDestroyed, UDestructibleSubHealthComponent*, subHealth);
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxHealth;
    float RadialDamageResistance;
    bool AllowInderectDamage;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Damage, meta=(AllowPrivateAccess=true))
    float Damage;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* ArmorComponent;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSubHealthDestroyed OnDestroyed;
    UDestructibleSubHealthComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void ResetHealth();
    UFUNCTION()
    void OnRep_Damage(float oldDamage);
};
