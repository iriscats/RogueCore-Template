#pragma once
#include "CoreMinimal.h"
#include "TXPlayerInfo.h"
#include "TXRunInfo.h"
#include "TXStageEndEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXStageEndEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 player_count;
    
    FString Result;
    int32 negotiation_count;
    int32 weapon_negotiation_count;
    int32 artifact_negotiation_count;
    int32 risk_vector_negotiation_count;
    FTXPlayerInfo player_info;
    FTXRunInfo run_info;
    ROGUECORE_API FTXStageEndEvent();
};
