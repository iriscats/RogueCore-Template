#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ETerrainPlacementBoxType.h"
#include "TerrainPlacementBox.generated.h"

USTRUCT(BlueprintType)
struct FTerrainPlacementBox {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector min;
    
    FVector max;
    ETerrainPlacementBoxType PlacementType;
    ROGUECORE_API FTerrainPlacementBox();
};
