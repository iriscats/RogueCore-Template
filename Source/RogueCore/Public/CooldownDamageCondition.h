#pragma once
#include "CoreMinimal.h"
#include "DamageCondition.h"
#include "CooldownDamageCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UCooldownDamageCondition : public UDamageCondition {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoolDown;

    UCooldownDamageCondition();

};
