#pragma once
#include "CoreMinimal.h"
#include "TXNegotiationEndEvent_RunInfo_CurrentStage.h"
#include "TXNegotiationEndEvent_RunInfo.generated.h"

USTRUCT(BlueprintType)
struct FTXNegotiationEndEvent_RunInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 run_duration;
    
    int32 team_level;
    int32 completed_stages;
    FTXNegotiationEndEvent_RunInfo_CurrentStage current_stage;
    ROGUECORE_API FTXNegotiationEndEvent_RunInfo();
};
