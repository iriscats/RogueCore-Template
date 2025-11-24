#pragma once
#include "CoreMinimal.h"
#include "ElementCondition.h"
#include "ChangeElementCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ROGUECORE_API UChangeElementCondition : public UElementCondition
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChangeThreshold;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CompareToAbsolute;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool MultiplyWithResistance;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IgnoreTriggerFromDecay;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AlsoCheckTransferElement;

public:
    UChangeElementCondition();
};
