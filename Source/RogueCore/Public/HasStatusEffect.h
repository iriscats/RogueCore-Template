#pragma once
#include "CoreMinimal.h"
#include "EStatusEffectStackMode.h"
#include "FindAllyConditionBase.h"
#include "Templates/SubclassOf.h"
#include "HasStatusEffect.generated.h"

class UStatusEffect;
UCLASS(Blueprintable, EditInlineNew)
class UHasStatusEffect : public UFindAllyConditionBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> StatusEffect;
    
    EStatusEffectStackMode Mode;
    int32 count;
    UHasStatusEffect();
};
