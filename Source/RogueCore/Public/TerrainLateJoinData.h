#pragma once
#include "CoreMinimal.h"
#include "CSGBuildOperationData.h"
#include "CarveWithColliderOperationData.h"
#include "CarveWithSTLMeshOperationData.h"
#include "DrillOperationData.h"
#include "GrenadeExplodeOperationData.h"
#include "MeltOperationData.h"
#include "PickaxeDigOperationData.h"
#include "RemoveFloatingIslandOperationData.h"
#include "SplineSegmentCarveOperationData.h"
#include "TerrainSpawnDebrisOperationData.h"
#include "TerrainLateJoinData.generated.h"

USTRUCT(BlueprintType)
struct FTerrainLateJoinData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FGrenadeExplodeOperationData> Explosions;
    
    TArray<FCarveWithColliderOperationData> ColliderCarves;
    TArray<FCarveWithSTLMeshOperationData> MeshCarves;
    TArray<FPickaxeDigOperationData> PickAxe;
    TArray<FRemoveFloatingIslandOperationData> RemoveFloating;
    TArray<FDrillOperationData> Drills;
    TArray<FMeltOperationData> Melts;
    TArray<FSplineSegmentCarveOperationData> Splines;
    TArray<FCSGBuildOperationData> CSGBuilds;
    TArray<FTerrainSpawnDebrisOperationData> SpawnDebris;
    TArray<int32> DebrisInstanceComponentPairs;
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<uint32> VisibleChunks;
    int32 OperationCount;
    ROGUECORE_API FTerrainLateJoinData();
};
