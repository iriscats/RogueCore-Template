#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "TunnelSegmentSetting.generated.h"

class UFloodFillSettings;
class UTerrainMaterial;
UCLASS(Blueprintable)
class UTunnelSegmentSetting : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTerrainMaterial* Material;
    
    UFloodFillSettings* PathfinderNoise;
    UFloodFillSettings* CielingNoise;
    UFloodFillSettings* WallNoise;
    UFloodFillSettings* FloorNoise;
    FVector2D VRange;
    FVector2D HRange;
    FVector2D Cielingheight;
    FVector2D FloorHeight;
    FVector2D CielingNoiseRange;
    FVector2D WallNoiseRange;
    FVector2D FloorNoiseRange;
    UTunnelSegmentSetting();
};
