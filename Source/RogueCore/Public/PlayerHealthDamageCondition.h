#pragma once
#include "CoreMinimal.h"

#include "DamageCondition.h"
#include "PlayerHealthDamageCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UPlayerHealthDamageCondition : public UDamageCondition {
    GENERATED_BODY()
    

public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval HealthPercentageRequired;
    
    UPlayerHealthDamageCondition();
};
