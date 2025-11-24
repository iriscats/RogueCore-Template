#pragma once
#include "CoreMinimal.h"
#include "DamageCondition.h"
#include "EDamageConditionDistanceMode.h"
#include "DistanceToTargetDamageCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UDistanceToTargetDamageCondition : public UDamageCondition {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumDistance;
    
    float MaxDistance;
    EDamageConditionDistanceMode Mode;
    UDistanceToTargetDamageCondition();
};
