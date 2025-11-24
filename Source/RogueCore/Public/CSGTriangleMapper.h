#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/DataAsset.h"
#include "CellNoise.h"
#include "DebrisCellNoiseParameters.h"
#include "CSGTriangleMapper.generated.h"

class UTerrainMaterial;
class UTerrainType;
UCLASS(Abstract, Blueprintable, EditInlineNew)
class UCSGTriangleMapper : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
    UTerrainMaterial* AttachToMaterial;
    UTerrainMaterial* BannedMaterial;
    TArray<UTerrainType*> AttachToTypes;
    int32 CellCategories;
    float DensityInM2;
    float MinVerticalAngle;
    float MaxVerticalAngle;
    FVector ScaleMin;
    FVector ScaleMax;
    float ScaleBias;
    bool IndependentScaleAxes;
    FVector BaseNormal;
    float SurfaceNormalFactor;
    FVector SurfaceNormalLimiter;
    float RandomNormalFactor;
    float InfluencerNormalFactor;
    float RotationMinAngle;
    float RotationMaxAngle;
    float PosOffset;
    float PosOffsetSurface;
    FRotator BaseRotation;
    TArray<FCellNoise> NoiseLayers;
    FDebrisCellNoiseParameters CellNoiseParameters;
    UCSGTriangleMapper();
};
