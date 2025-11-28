#pragma once
#include "CoreMinimal.h"
#include "DamageBonusBase.h"
#include "BreakIceBonus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UBreakIceBonus : public UDamageBonusBase {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DeFrostAmount;
    
    UBreakIceBonus();
};
