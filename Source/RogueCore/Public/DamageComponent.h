#pragma once
#include "CoreMinimal.h"

#include "GameplayTagContainer.h"
#include "DamageComponentBase.h"
#include "EArmorDamageType.h"
#include "OnAsyncAoE_CompleteDelegate.h"
#include "OnNoTargetHitDelegate.h"
#include "Templates/SubclassOf.h"
#include "DamageComponent.generated.h"

class UDamageBonusBase;
class UDamageClass;
class UDamageImpulse;
class UDamageModifier;
class UDamageTag;
class UElementEventTypeBase;
UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UDamageComponent : public UDamageComponentBase {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintAuthorityOnly, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnNoTargetHit OnNoTargetHitEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnAsyncAoE_Complete OnAsyncAoE_Complete;
 
    UDamageImpulse* DamageImpulse;
    float Damage;
    float armorDamageMultiplier;
    float ArmorPenetration;
    bool ShattersArmor;
    UDamageClass* DamageClass;
    EArmorDamageType ArmorDamageType;
    float WeakpointDamageMultiplier;
    float FrozenDamageBonusScale;
    TMap<TSubclassOf<UElementEventTypeBase>, float> ElementEventDamageBonusScaleOverride;
    float FriendlyFireModifier;
    float SelfFriendlyFireMultiplier;
    FGameplayTag FriendlyFireTag;
    bool StaggerOnlyOnWeakpointHit;
    float StaggerChance;
    float StaggerDuration;
    float FearFactor;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UDamageBonusBase*> DamageBonuses;
    TArray<UDamageModifier*> DamageModifiers;
    TArray<UDamageTag*> DamageTags;
    bool UseAreaOfEffect;
    float RadialDamage;
    bool NoFriendlyFireFromRadial;
    bool IgnoreOwnerFromRadial;
    UDamageClass* RadialDamageClass;
    float MinDamagePct;
    float DamageRadius;
    float MaxDamageRadius;
    UDamageComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void PreTestDamageConditions();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetDamage() const;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintPure=false)
    void DamageTargetFromHit(const FHitResult& HitResult) const;
};
