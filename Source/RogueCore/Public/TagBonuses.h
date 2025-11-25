#pragma once
#include "CoreMinimal.h"
#include "TagBonuses.generated.h"

class UActorComponent;
class UDamageBonusBase;
class UTagEffectBase;
class UWeaponTagBase;
USTRUCT(BlueprintType)
struct FTagBonuses {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UTagEffectBase*> OnHitBonuses;
    
    TArray<UTagEffectBase*> OnKillBonuses;
    TArray<UTagEffectBase*> OnCritBonuses;
    TArray<UTagEffectBase*> OnPowerAttackBonuses;
    TArray<UDamageBonusBase*> DamageBonuses;
    UPROPERTY(EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<UActorComponent>> SpecialBonuses;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWeaponTagBase* Tag;
 
    float DamageBonus;
    float DamageMultiplier;
    float WeakpointMultiplier;
    float CritChanceBonus;
    float ReloadSpeedMultiplier;
    float ReloadSpeedBonusWhenEmptyMultiplier;
    float CapacityMultiplier;
    float MagazineMultiplier;
    ROGUECORE_API FTagBonuses();
};
