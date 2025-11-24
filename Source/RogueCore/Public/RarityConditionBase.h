#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "RarityConditionBase.generated.h"

UCLASS(Abstract, Blueprintable)
class URarityConditionBase : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InvertResult;

protected:
    URarityConditionBase();
};
