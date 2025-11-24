#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ValidatorStrategy.generated.h"

UCLASS(Abstract, Blueprintable)
class ROGUECORE_API UValidatorStrategy : public UObject {
    GENERATED_BODY()
public:
    UValidatorStrategy();
};
