#pragma once
#include "CoreMinimal.h"
#include "TagEffectCondition.h"
#include "TagDistanceCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UTagDistanceCondition : public UTagEffectCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Distance;
    
    UTagDistanceCondition();
};
