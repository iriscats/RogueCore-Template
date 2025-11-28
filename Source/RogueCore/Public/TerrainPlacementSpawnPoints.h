#pragma once
#include "CoreMinimal.h"

#include "EStaticSpawnPointSelectionType.h"
#include "TerrainPlacementSpawnPoints.generated.h"

USTRUCT(BlueprintType)
struct FTerrainPlacementSpawnPoints {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EStaticSpawnPointSelectionType Type;
    
    float SpawnProbability;
    FVector SpawnCenter;
    float SpawnRadius;
    ROGUECORE_API FTerrainPlacementSpawnPoints();
};
