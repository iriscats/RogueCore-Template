#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "LayeredNoise.h"
#include "FloodFillSettings.generated.h"

UCLASS(Blueprintable)
class UFloodFillSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector NoiseSize;
    
    float FreqMultiplier;
    float AmplitudeMultiplier;
    float MinValue;
    float MaxValue;
    bool Turbulence;
    bool Invert;
    int32 Octaves;
    TArray<FLayeredNoise> NoiseLayers;
    UFloodFillSettings();
};
