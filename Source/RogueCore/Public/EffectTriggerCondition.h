#pragma once
#include "CoreMinimal.h"
#include "EffectTriggerCondition.generated.h"

UCLASS(Abstract, Blueprintable)
class ROGUECORE_API UEffectTriggerCondition : public UObject
{
    GENERATED_BODY()
public:
    UEffectTriggerCondition();

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool invertCondition;
};