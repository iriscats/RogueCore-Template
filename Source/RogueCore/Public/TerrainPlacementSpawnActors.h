#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TerrainPlacementSpawnActors.generated.h"

class AActor;
class UDebrisPositioning;
USTRUCT(BlueprintType)
struct FTerrainPlacementSpawnActors {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> SpawnActorClass;
    
    UDebrisPositioning* SpawnPositioning;
    int32 AmountToSpawn;
    int32 AmountToSpawnMinimum;
    int32 NumberOfAllowedChecks;
    float MinimumDistanceBetweenSpawns;
    bool AddTerrainPlacementBlockers;
    ROGUECORE_API FTerrainPlacementSpawnActors();
};
