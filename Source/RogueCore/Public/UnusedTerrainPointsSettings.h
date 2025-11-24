#pragma once
#include "CoreMinimal.h"
#include "EStaticSpawnPointSelectionType.h"
#include "UnusedTerrainPointsSettings.generated.h"

USTRUCT(BlueprintType)
struct FUnusedTerrainPointsSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PointsPerOwner;
    
    bool AddTerrainPlacementBlockers;
    EStaticSpawnPointSelectionType PointType;
    ROGUECORE_API FUnusedTerrainPointsSettings();
};
