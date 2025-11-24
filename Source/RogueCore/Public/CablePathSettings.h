#pragma once
#include "CoreMinimal.h"
#include "DeepPathFinderPreference.h"
#include "DeepPathFinderSize.h"
#include "DeepPathFinderType.h"
#include "CablePathSettings.generated.h"

USTRUCT(BlueprintType)
struct FCablePathSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    DeepPathFinderType PathType;
    
    DeepPathFinderSize PathSize;
    DeepPathFinderPreference PathPreference;
    float MinStepSize;
    float MaxStepSize;
    float MaxNoiseY;
    float MinSurfaceHeight;
    float MaxSurfaceHeight;
    ROGUECORE_API FCablePathSettings();
};
