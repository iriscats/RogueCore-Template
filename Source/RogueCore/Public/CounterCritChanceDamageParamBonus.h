#pragma once
#include "CoreMinimal.h"
#include "DamageParamBonus.h"
#include "CounterCritChanceDamageParamBonus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UCounterCritChanceDamageParamBonus : public UDamageParamBonus {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AdditionalCritChance;
    
    UCounterCritChanceDamageParamBonus();
};
