#pragma once
#include "CoreMinimal.h"
#include "AbilityUpgrade.h"
#include "Templates/SubclassOf.h"
#include "ProjectileAbilityUpgrade.generated.h"

class AProjectileBase;
class UDamageBonusBase;
class UWeaponTagBase;
UCLASS(Blueprintable, EditInlineNew)
class UProjectileAbilityUpgrade : public UAbilityUpgrade {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AProjectileBase> ProjectileClass;
    
    UWeaponTagBase* DamageTag;
    UDamageBonusBase* Damage;
    UProjectileAbilityUpgrade();
};
