#pragma once
#include "CoreMinimal.h"
#include "TXStageStartEvent_CaveGeneration_SpawnedObjectives_Failures.h"
#include "TXStageStartEvent_CaveGeneration_SpawnedObjectives_Successes.h"
#include "TXStageStartEvent_CaveGeneration_SpawnedObjectives.generated.h"

USTRUCT(BlueprintType)
struct FTXStageStartEvent_CaveGeneration_SpawnedObjectives {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTXStageStartEvent_CaveGeneration_SpawnedObjectives_Failures> failures;
    
    TArray<FTXStageStartEvent_CaveGeneration_SpawnedObjectives_Successes> successes;
    ROGUECORE_API FTXStageStartEvent_CaveGeneration_SpawnedObjectives();
};
