#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "RandRange.h"
#include "RandomDamageBonus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class URandomDamageBonus : public UDamageBonusBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRandRange RandomDamageRange;
    
    URandomDamageBonus();
};
