#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "WaveDifficultyRanges.generated.h"

USTRUCT(BlueprintType)
struct FWaveDifficultyRanges {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Used;
    
    FRuntimeFloatCurve OverTimeInterval;
    ROGUECORE_API FWaveDifficultyRanges();
};
