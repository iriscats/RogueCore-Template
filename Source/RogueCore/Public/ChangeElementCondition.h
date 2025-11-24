#pragma once
#include "CoreMinimal.h"
#include "ElementCondition.h"
#include "ChangeElementCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UChangeElementCondition : public UElementCondition {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChangeThreshold;

    bool CompareToAbsolute;

    bool MultiplyWithResistance;

    bool IgnoreTriggerFromDecay;

    bool AlsoCheckTransferElement;

public:
    UChangeElementCondition();
};
