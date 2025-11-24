#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "HealthModifier.h"
#include "HealthCurveModifier.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class UHealthCurveModifier : public UHealthModifier {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRuntimeFloatCurve Curve;
    
    UHealthCurveModifier();
};
