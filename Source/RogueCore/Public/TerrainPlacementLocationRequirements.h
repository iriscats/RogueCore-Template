#pragma once
#include "CoreMinimal.h"

#include "TerrainPlacementLocationRequirements.generated.h"

class UCurveFloat;
USTRUCT(BlueprintType)
struct FTerrainPlacementLocationRequirements {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector> Locations;
    
    UCurveFloat* DistanceCostCurve;
    bool AvoidImportantLocations;
    float MinimumDistanceToImportantLocation;
    ROGUECORE_API FTerrainPlacementLocationRequirements();
};
