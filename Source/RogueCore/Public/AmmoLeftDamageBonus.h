#pragma once
#include "CoreMinimal.h"
#include "FlatDamageBonus.h"
#include "AmmoLeftDamageBonus.generated.h"

class UCurveFloat;
UCLASS(Blueprintable, EditInlineNew)
class UAmmoLeftDamageBonus : public UFlatDamageBonus {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* AmmoDamageCurve;
    
    UAmmoLeftDamageBonus();
};
