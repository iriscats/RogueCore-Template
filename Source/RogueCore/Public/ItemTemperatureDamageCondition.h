#pragma once
#include "CoreMinimal.h"
#include "DamageCondition.h"
#include "ItemTemperatureDamageCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UItemTemperatureDamageCondition : public UDamageCondition {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HeatThreshold;
    
    bool MustBeUnderThreshold;
    UItemTemperatureDamageCondition();
};
