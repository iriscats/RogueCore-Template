#pragma once
#include "CoreMinimal.h"
#include "EPawnStatType.h"
#include "PerkEffect.h"
#include "PerkEffectStatChange.generated.h"

class UPawnStat;
UCLASS(Blueprintable, EditInlineNew)
class UPerkEffectStatChange : public UPerkEffect {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPawnStat* PawnStat;
    
    EPawnStatType StatType;
    UPerkEffectStatChange();
};
