#pragma once
#include "CoreMinimal.h"
#include "StatusEffectItem.h"
#include "StatChangeStackedStatusEffectItem.generated.h"

class UPawnStat;
UCLASS(Blueprintable, EditInlineNew)
class UStatChangeStackedStatusEffectItem : public UStatusEffectItem {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPawnStat* Stat;
    
    float StatChange;
    bool AffectedByResistances;
    UStatChangeStackedStatusEffectItem();
};
