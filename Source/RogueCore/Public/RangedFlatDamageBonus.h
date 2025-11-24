#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "RangedFlatDamageBonus.generated.h"

class UCurveFloat;
class UDamageClass;
UCLASS(Blueprintable, EditInlineNew)
class URangedFlatDamageBonus : public UDamageBonusBase {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* DamageCurve;
    
    UDamageClass* DamageClass;
    URangedFlatDamageBonus();
};
