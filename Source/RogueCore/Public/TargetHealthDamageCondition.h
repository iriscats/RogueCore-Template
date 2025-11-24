#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DamageCondition.h"
#include "TargetHealthDamageCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UTargetHealthDamageCondition : public UDamageCondition {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval HealthPercentageRequired;
    
    UTargetHealthDamageCondition();
};
