#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "CritDamageBonus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UCritDamageBonus : public UDamageBonusBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AdditionalCritDamagePercent;

    UCritDamageBonus();

};
