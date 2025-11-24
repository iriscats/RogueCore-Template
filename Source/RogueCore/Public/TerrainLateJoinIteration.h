#pragma once
#include "CoreMinimal.h"
#include "TerrainLateJoinIteration.generated.h"

USTRUCT(BlueprintType)
struct FTerrainLateJoinIteration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 DrillsIndex;
    
    int32 MeltsIndex;
    int32 PickAxeIndex;
    int32 FloatingIndex;
    int32 ColliderCarvesIndex;
    int32 MeshCarvesIndex;
    int32 ExplosionsIndex;
    int32 SplineIndex;
    int32 CSGIndex;
    int32 SpawnDebrisIndex;
    int32 LateJoinIndex;
    int32 DebrisIndex;
    int32 ChunkVisibilityIndex;
    ROGUECORE_API FTerrainLateJoinIteration();
};
