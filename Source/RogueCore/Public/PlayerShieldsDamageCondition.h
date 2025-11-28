#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DamageCondition.h"
#include "PlayerShieldsDamageCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UPlayerShieldsDamageCondition : public UDamageCondition {
    GENERATED_BODY()
    
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval ShieldPercentageRequired;
    
    UPlayerShieldsDamageCondition();
};
