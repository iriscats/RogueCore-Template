#pragma once
#include "CoreMinimal.h"
#include "CSGOptions.h"
#include "CarveOptionsCellSize.h"
#include "CarveSplineSegment.h"
#include "ECarveFilterType.h"
#include "MatrixWithExactSync.h"
#include "EDebrisItemPass.h"
#include "ELevelCarverType.h"
#include "Templates/SubclassOf.h"
#include "LevelGenerationCarver.generated.h"

class ACSGBuilder;
class USTLMeshCarver;
class UStaticMesh;
class UStaticMeshCarver;
class UTerrainMaterial;
USTRUCT(BlueprintType)
struct FLevelGenerationCarver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMatrixWithExactSync Transform;
    
    USTLMeshCarver* MeshCarver;
    UStaticMesh* ConvexCarver;
    UStaticMeshCarver* StaticMeshCarver;
    TSubclassOf<ACSGBuilder> CSGCarver;
    FCSGOptions CSGCarverSettings;
    float ConvexExpensiveNoise;
    CarveOptionsCellSize CarveCellSize;
    UTerrainMaterial* TerrainMaterial;
    ELevelCarverType Type;
    ECarveFilterType Filter;
    EDebrisItemPass CarvePass;
    TArray<FCarveSplineSegment> SplineSegments;
    bool UseCarvePass;
    bool ToBeDiscarded;
    ROGUECORE_API FLevelGenerationCarver();
};
