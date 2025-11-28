#pragma once
#include "CoreMinimal.h"

#include "TerrainPlacementSpawnSphere.generated.h"

USTRUCT(BlueprintType)
struct FTerrainPlacementSpawnSphere {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector SpawnCenter = FVector::ZeroVector;
    
    float SpawnRadius;

};
