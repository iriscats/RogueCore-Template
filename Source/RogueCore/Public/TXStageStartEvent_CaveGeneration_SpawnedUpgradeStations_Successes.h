#pragma once
#include "CoreMinimal.h"
#include "TXStageStartEvent_CaveGeneration_SpawnedUpgradeStations_Successes.generated.h"

USTRUCT(BlueprintType)
struct FTXStageStartEvent_CaveGeneration_SpawnedUpgradeStations_Successes {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    int32 amount;
    ROGUECORE_API FTXStageStartEvent_CaveGeneration_SpawnedUpgradeStations_Successes();
};
