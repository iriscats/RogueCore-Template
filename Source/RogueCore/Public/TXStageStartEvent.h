#pragma once
#include "CoreMinimal.h"
#include "TXPlayerInfo.h"
#include "TXRunInfo.h"
#include "TXStageStartEvent_CaveGeneration.h"
#include "TXStageStartEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXStageStartEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 player_count;
    
    int32 negotiation_count;
    int32 weapon_negotiation_count;
    int32 artifact_negotiation_count;
    int32 risk_vector_negotiation_count;
    FTXStageStartEvent_CaveGeneration cave_generation;
    FTXPlayerInfo player_info;
    FTXRunInfo run_info;
    ROGUECORE_API FTXStageStartEvent();
};
