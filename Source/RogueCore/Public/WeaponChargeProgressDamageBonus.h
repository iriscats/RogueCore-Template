#pragma once
#include "CoreMinimal.h"

#include "ItemUpgrade.h"
#include "WeaponChargeProgressDamageBonus.generated.h"

class UDamageClass;
UCLASS(Blueprintable, EditInlineNew, MinimalAPI)
class UWeaponChargeProgressDamageBonus : public UItemUpgrade {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageClass* DamageClass;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval ChargeRange;
    FFloatInterval DamageBonusRange;
    UWeaponChargeProgressDamageBonus();
};
