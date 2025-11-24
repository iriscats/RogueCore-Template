#pragma once
#include "CoreMinimal.h"
#include "TXUpgradeNegotiationEndEvent_RunInfo_CurrentStage.h"
#include "TXUpgradeNegotiationEndEvent_RunInfo_OngoingGameevents.h"
#include "TXUpgradeNegotiationEndEvent_RunInfo.generated.h"

USTRUCT(BlueprintType)
struct FTXUpgradeNegotiationEndEvent_RunInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Duration;
    
    int32 team_level;
    int32 completed_stages;
    FTXUpgradeNegotiationEndEvent_RunInfo_CurrentStage current_stage;
    FTXUpgradeNegotiationEndEvent_RunInfo_OngoingGameevents ongoing_gameevents;
    ROGUECORE_API FTXUpgradeNegotiationEndEvent_RunInfo();
};
