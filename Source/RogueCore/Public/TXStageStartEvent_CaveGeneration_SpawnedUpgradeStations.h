#pragma once
#include "CoreMinimal.h"
#include "TXStageStartEvent_CaveGeneration_SpawnedUpgradeStations_Failures.h"
#include "TXStageStartEvent_CaveGeneration_SpawnedUpgradeStations_Successes.h"
#include "TXStageStartEvent_CaveGeneration_SpawnedUpgradeStations.generated.h"

USTRUCT(BlueprintType)
struct FTXStageStartEvent_CaveGeneration_SpawnedUpgradeStations {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTXStageStartEvent_CaveGeneration_SpawnedUpgradeStations_Failures> failures;
    
    TArray<FTXStageStartEvent_CaveGeneration_SpawnedUpgradeStations_Successes> successes;
    ROGUECORE_API FTXStageStartEvent_CaveGeneration_SpawnedUpgradeStations();
};
