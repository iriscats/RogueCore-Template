#pragma once
#include "CoreMinimal.h"
#include "RandRange.h"
#include "StatusEffectItem.h"
#include "HealingStatusEffectItem.generated.h"

class UPawnAffliction;
UCLASS(Blueprintable, EditInlineNew)
class UHealingStatusEffectItem : public UStatusEffectItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HealPercentage;
    
    float NoDamageTimeRequired;
    UPawnAffliction* PawnAffliction;
    FRandRange amount;
    bool IgnoreCanTakeDamage;
    UHealingStatusEffectItem();
};
