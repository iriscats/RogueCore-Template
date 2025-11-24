#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "BreakIceBonus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UBreakIceBonus : public UDamageBonusBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeFrostAmount;
    
    UBreakIceBonus();
};
