#pragma once
#include "CoreMinimal.h"
#include "ElementConditionArray.generated.h"

class UElementCondition;
USTRUCT(BlueprintType)
struct FElementConditionArray {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UElementCondition*> Conditions;

    FElementConditionArray() {}
};
