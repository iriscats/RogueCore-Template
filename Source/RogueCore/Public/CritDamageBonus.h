#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "CritDamageBonus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UCritDamageBonus : public UDamageBonusBase {
    GENERATED_BODY()
    

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AdditionalCritDamagePercent;

    UCritDamageBonus();

};
