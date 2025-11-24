#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "PercentDamageBonus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UPercentDamageBonus : public UDamageBonusBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PercentBonus;
    
    UPercentDamageBonus();
};
