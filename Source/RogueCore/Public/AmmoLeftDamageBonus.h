#pragma once
#include "CoreMinimal.h"
#include "FlatDamageBonus.h"
#include "AmmoLeftDamageBonus.generated.h"

class UCurveFloat;
UCLASS(Blueprintable, EditInlineNew)
class UAmmoLeftDamageBonus : public UFlatDamageBonus {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* AmmoDamageCurve;
    
    UAmmoLeftDamageBonus();
};
