#pragma once
#include "CoreMinimal.h"
#include "WeightedLinePoint.h"
#include "Pillar.generated.h"

class UFloodFillSettings;
USTRUCT(BlueprintType)
struct FPillar {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFloodFillSettings* NoiseOverride;
    
    TArray<FWeightedLinePoint> Points;
    float NoiseScale;
    float EndcapScale;
    ROGUECORE_API FPillar();
};
