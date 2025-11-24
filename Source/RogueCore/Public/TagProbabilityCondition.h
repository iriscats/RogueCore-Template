#pragma once
#include "CoreMinimal.h"
#include "TagEffectCondition.h"
#include "TagProbabilityCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UTagProbabilityCondition : public UTagEffectCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Probability;
    
    UTagProbabilityCondition();
};
