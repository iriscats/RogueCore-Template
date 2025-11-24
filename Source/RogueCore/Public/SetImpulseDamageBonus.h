#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "SetImpulseDamageBonus.generated.h"

class UDamageImpulse;
UCLASS(Blueprintable, EditInlineNew)
class USetImpulseDamageBonus : public UDamageBonusBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageImpulse* DamageImpulse;
    
    USetImpulseDamageBonus();
};
