#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "FindAllyConditionBase.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class UFindAllyConditionBase : public UObject {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Invert;

public:
    UFindAllyConditionBase();
};
