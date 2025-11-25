#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "NoiseVisualizor.generated.h"

class UFloodFillSettings;
UCLASS(Blueprintable)
class ANoiseVisualizor : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFloodFillSettings* FloodFillSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float FreqMultiplier;
    float AmplitudeMultiplier;
    FVector NoiseSize;
    float PointSize;
    float PostNoiseAmplitude;
    int32 Octaves;
    FVector Origin;
    bool ShowNoise;
    bool ShowTerrainNoise;
    ANoiseVisualizor(const FObjectInitializer& ObjectInitializer);
};
