#pragma once
#include "CoreMinimal.h"
#include "RandRange.h"
#include "StatusEffectItem.h"
#include "DotStatusEffectItem.generated.h"

class UDamageImpulse;
UCLASS(Blueprintable, EditInlineNew)
class UDotStatusEffectItem : public UStatusEffectItem {
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRandRange damageAmount;
    
    bool OverrideDamageImpulse;
    bool ChangeElementValueAtMax;
    UDamageImpulse* DamageImpulseOverride;
    UDotStatusEffectItem();
};
