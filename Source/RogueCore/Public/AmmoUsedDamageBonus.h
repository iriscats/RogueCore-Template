#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "AmmoUsedDamageBonus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UAmmoUsedDamageBonus : public UDamageBonusBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DamageBonusPerRoundFired;
    
    UAmmoUsedDamageBonus();
};
