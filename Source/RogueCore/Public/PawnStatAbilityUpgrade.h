#pragma once
#include "CoreMinimal.h"
#include "AbilityUpgrade.h"
#include "PawnStatAbilityUpgrade.generated.h"

class UPawnStat;
UCLASS(Blueprintable, EditInlineNew)
class UPawnStatAbilityUpgrade : public UAbilityUpgrade {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPawnStat* PawnStat;
    
    UPawnStatAbilityUpgrade();
};
