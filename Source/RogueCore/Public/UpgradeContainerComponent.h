#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DamageRelevant.h"
#include "EDamageUpgrade.h"
#include "UpgradeContainerComponent.generated.h"

class AActor;
class UDamageBonusBase;
class UDamageParamBonus;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UUpgradeContainerComponent : public UActorComponent, public IDamageRelevant {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))

    float NumericalDamageUpgrades[15];

    float NumericalUpgrades[5];

    UUpgradeContainerComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TArray<UDamageBonusBase*> DamageBonusUpgrades;
    
    TArray<UDamageParamBonus*> DamageParamBonuses;
    UPROPERTY(EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    float NumericalDamageUpgrades[15];
    float NumericalUpgrades[5];
    UUpgradeContainerComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    static void RemoveFloatUpgrade(AActor* Target, EDamageUpgrade upgradeType, float Value);
    static void RemoveDynamicUpgrade(AActor* Target, UDamageBonusBase* DamageBonus);
    static void RemoveDamageParamBonus(AActor* Target, UDamageParamBonus* DamageBonus);
    static void AddFloatUpgrade(AActor* Target, EDamageUpgrade upgradeType, float Value);
    static void AddDynamicUpgrade(AActor* Target, UDamageBonusBase* DamageBonus);
    static void AddDamageParamBonus(AActor* Target, UDamageParamBonus* DamageBonus);
    // Fix for true pure virtual functions not being implemented
};
