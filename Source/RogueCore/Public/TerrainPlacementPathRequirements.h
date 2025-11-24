#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TerrainPlacementPathRequirements.generated.h"

USTRUCT(BlueprintType)
struct FTerrainPlacementPathRequirements {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RequirePath;
    
    FVector RequirePathTo;
    float MinimumDistance;
    float MaximumDistance;
    ROGUECORE_API FTerrainPlacementPathRequirements();
};
