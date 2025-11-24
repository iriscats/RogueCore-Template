#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "RewinderKnobIdle.generated.h"

class UAnimMontage;
USTRUCT(BlueprintType)
struct FRewinderKnobIdle {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* Animation;
    
    FRuntimeFloatCurve SpinDegrees;
    bool Enabled;
    ROGUECORE_API FRewinderKnobIdle();
};
