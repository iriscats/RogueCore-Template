#pragma once
#include "CoreMinimal.h"

#include "DamageCondition.h"
#include "TargetHealthDamageCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UTargetHealthDamageCondition : public UDamageCondition {
    GENERATED_BODY()
    

public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval HealthPercentageRequired;
    
    UTargetHealthDamageCondition();
};
