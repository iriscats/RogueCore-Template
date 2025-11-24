#pragma once
#include "CoreMinimal.h"
#include "TXStageStartEvent_CaveGeneration_SpawnedUpgradeStations_Failures.generated.h"

USTRUCT(BlueprintType)
struct FTXStageStartEvent_CaveGeneration_SpawnedUpgradeStations_Failures {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    int32 amount;
    ROGUECORE_API FTXStageStartEvent_CaveGeneration_SpawnedUpgradeStations_Failures();
};
