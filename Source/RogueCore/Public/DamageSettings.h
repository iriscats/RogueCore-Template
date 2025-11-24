#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Curves/CurveFloat.h"
#include "GameplayTagContainer.h"
#include "DamageInstance.h"
#include "DecalData.h"
#include "Templates/SubclassOf.h"
#include "DamageSettings.generated.h"

class UDamageComponent;
class UDamageImpulse;
class UDamageTag;
class UNiagaraSystem;
class USoundCue;
class UStatusEffect;
class UWeaponTagBase;
UCLASS(Blueprintable)
class UDamageSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TemperatureChangePerColdDamagePoint;
    
    float TemperatureChangePerIceDamagePoint;
    float TemperatureChangePerHeatDamagePoint;
    float TemperatureChangePerFireDamagePoint;
    float TemperatureShockActivationWindow;
    float FrozenDamageBonus;
    TSubclassOf<UStatusEffect> EnemyOnFireStatusEffect;
    TSubclassOf<UStatusEffect> PlayerOnFireStatusEffect;
    TSubclassOf<UStatusEffect> TemperatureShockFromFrozenStatusEffect;
    TSubclassOf<UStatusEffect> TemperatureShockFromBurningStatusEffect;
    float InfectionPerDamagePoint;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* ArmorShatterDamage;
    UDamageComponent* ChemicalExplosionDamage;
    TArray<FDamageInstance> ChemicalExplosionDamageInstances;
    UNiagaraSystem* ArmorShatterEmitter;
    USoundCue* ArmorShatterSound;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, EditFixedSize, meta=(AllowPrivateAccess=true))
    TArray<FDecalData> ImpactDecals;
    FRuntimeFloatCurve ArmorToArmorDamageBreakingCurve;
    float RadialHealthArmorDamageFalloff;
    int32 HealthArmorBonesAffectedByRadialDamage;
    UDamageTag* DetonateFrozen;
    UDamageTag* DetonateOnFire;
    UDamageTag* DirectHit;
    UDamageTag* MeltTarget;
    UDamageTag* CookTarget;
    UDamageTag* GibTarget;
    UDamageTag* ExplodeOnDeath;
    UDamageTag* IgnoreBodypartDamageReduction;
    UDamageImpulse* DefaultDamageImpulse;
    UDamageImpulse* DoTDamageImpulse;
    float RagdollGlobalForceMultiplier;
    TMap<FGameplayTag, UWeaponTagBase*> WeaponTags;
    UDamageSettings();
};
