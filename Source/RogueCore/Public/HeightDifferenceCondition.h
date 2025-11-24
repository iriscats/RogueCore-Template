#pragma once
#include "CoreMinimal.h"
#include "DamageCondition.h"
#include "EHeightDiffrenceTargetingMode.h"
#include "HeightDifferenceCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UHeightDifferenceCondition : public UDamageCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetDifference;
    
    EHeightDiffrenceTargetingMode Mode;
    UHeightDifferenceCondition();
};
