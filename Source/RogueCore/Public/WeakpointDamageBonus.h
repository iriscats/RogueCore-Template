#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "WeakpointDamageBonus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UWeakpointDamageBonus : public UDamageBonusBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AdditionalWeakpointDamage;
    
    UWeakpointDamageBonus();
};
