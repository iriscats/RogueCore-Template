#pragma once
#include "CoreMinimal.h"
#include "DamageCondition.h"
#include "EDirectDamageConditionEnum.h"
#include "DirectDamageCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UDirectDamageCondition : public UDamageCondition {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDirectDamageConditionEnum Type;
    
    UDirectDamageCondition();
};
