#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TerrainPlacementDistanceRequirements.generated.h"

USTRUCT(BlueprintType)
struct FTerrainPlacementDistanceRequirements {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RequireDistance;
    
    FVector DistanceTo;
    float MinimumDistance;
    float MaximumDistance;
    ROGUECORE_API FTerrainPlacementDistanceRequirements();
};
