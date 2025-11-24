#pragma once
#include "CoreMinimal.h"
#include "DamageParamBonus.h"
#include "WeakpointCritDamageParamBonus.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UWeakpointCritDamageParamBonus : public UDamageParamBonus {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AdditionalCritChance;
    
    UWeakpointCritDamageParamBonus();
};
