#pragma once
#include "CoreMinimal.h"
#include "ETagEffectTarget.h"
#include "TagEffectCondition.h"
#include "TagHealthCondition.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UTagHealthCondition : public UTagEffectCondition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HealthIsMoreThan;
    
    bool UsePercent;
    ETagEffectTarget CheckHealthOn;
    UTagHealthCondition();
};
