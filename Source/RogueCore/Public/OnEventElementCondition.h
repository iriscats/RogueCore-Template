#pragma once
#include "CoreMinimal.h"
#include "ElementCondition.h"
#include "OnEventElementCondition.generated.h"

class UElementEventType;
UCLASS(Blueprintable, EditInlineNew)
class UOnEventElementCondition : public UElementCondition {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UElementEventType* EventToCheck;
    
    UOnEventElementCondition();
};
