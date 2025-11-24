#pragma once
#include "CoreMinimal.h"
#include "EDLSSUpscalerModularFeatureQuality.generated.h"

UENUM(BlueprintType)
enum class EDLSSUpscalerModularFeatureQuality : uint8 {
    UltraQuality,
    Quality,
    Balanced,
    Performance,
    UltraPerformance,
    DLAA,
    Count,
};

