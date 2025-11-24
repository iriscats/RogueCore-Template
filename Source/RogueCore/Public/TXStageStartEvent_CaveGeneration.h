#pragma once
#include "CoreMinimal.h"
#include "TXStageStartEvent_CaveGeneration_Biome.h"
#include "TXStageStartEvent_CaveGeneration_LevelDecoration.h"
#include "TXStageStartEvent_CaveGeneration_Resources.h"
#include "TXStageStartEvent_CaveGeneration_SpawnedObjectives.h"
#include "TXStageStartEvent_CaveGeneration_SpawnedUpgradeStations.h"
#include "TXStageStartEvent_CaveGeneration.generated.h"

USTRUCT(BlueprintType)
struct FTXStageStartEvent_CaveGeneration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FString> stationary_enemies;
    
    FTXStageStartEvent_CaveGeneration_LevelDecoration level_decoration;
    FTXStageStartEvent_CaveGeneration_SpawnedObjectives spawned_objectives;
    FTXStageStartEvent_CaveGeneration_SpawnedUpgradeStations spawned_upgrade_stations;
    TArray<FTXStageStartEvent_CaveGeneration_Resources> Resources;
    FTXStageStartEvent_CaveGeneration_Biome Biome;
    ROGUECORE_API FTXStageStartEvent_CaveGeneration();
};
