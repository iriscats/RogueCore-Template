#pragma once
#include "CoreMinimal.h"
#include "ElementCondition.h"
#include "ElementValueRange.h"
#include "RangeElementCondition.generated.h"

class UElementType;
UCLASS(Blueprintable, EditInlineNew)
class URangeElementCondition : public UElementCondition {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UElementType* ElementType;
    
    FElementValueRange Range;
    URangeElementCondition();
};
