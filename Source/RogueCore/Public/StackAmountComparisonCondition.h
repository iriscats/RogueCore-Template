#pragma once
#include "CoreMinimal.h"
#include "EStackComparisonMethod.h"
#include "ElementCondition.h"
#include "StackAmountComparisonCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UStackAmountComparisonCondition : public UElementCondition {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StackAmountCheck;
    
    EStackComparisonMethod ComparisonMethod;
    UStackAmountComparisonCondition();
};
