#pragma once
#include "CoreMinimal.h"
#include "BiomeNoiseItem.generated.h"

class UDetailNoise;
class UFloodFillSettings;
USTRUCT(BlueprintType)
struct FBiomeNoiseItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFloodFillSettings* CeilingNoise;
    
    UDetailNoise* CeilingDetailNoise;
    UFloodFillSettings* WallNoise;
    UDetailNoise* WallDetailNoise;
    UFloodFillSettings* FloorNoise;
    UDetailNoise* FloorDetailNoise;
    float Weight;
    ROGUECORE_API FBiomeNoiseItem();
};
