#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EArmorDamageType.h"
#include "EDamageMethod.h"
#include "EDamageVector.h"
#include "ElementParams.h"
#include "Templates/SubclassOf.h"
#include "DamageInstance.generated.h"

class UDamageBonusBase;
class UDamageClass;
class UDamageImpulse;
class UDamageModifier;
class UDamageTag;
class UElementEventTypeBase;
USTRUCT(BlueprintType)
struct FDamageInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UDamageTag*> DamageTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UDamageBonusBase*> DamageBonuses;
    TArray<UDamageModifier*> DamageModifiers;
    FGameplayTag FriendlyFireTag;
    EDamageVector DamageVector;
    UDamageClass* DamageType;
    FElementParams ElementParams;
    UDamageImpulse* DamageImpulse;
    float Damage;
    float StaggerChance;
    float StaggerDuration;
    float FearFactor;
    float FrozenMultiplier;
    float FriendlyFireMultiplier;
    float SelfMultiplier;
    float ArmorPenetration;
    float ArmorMultiplier;
    float Radius;
    float MinDamagePct;
    float MaxDamageRadius;
    float WeakpointMultiplier;
    TMap<TSubclassOf<UElementEventTypeBase>, float> ElementEventDamageBonusScaleOverride;
    EArmorDamageType ArmorDamageType;
    EDamageMethod Method;
    bool StaggerOnlyOnWeakpointHit;
    bool ShattersArmor;
    bool Enabled;
    bool NotifyListeners;
    bool DynamicBonusesEnabled;
    bool CanCrit;
    ROGUECORE_API FDamageInstance();
};
