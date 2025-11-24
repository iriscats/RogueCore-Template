#pragma once
#include "CoreMinimal.h"
#include "TXArtifactNegotiationEndEvent_RunInfo_CurrentStage.h"
#include "TXArtifactNegotiationEndEvent_RunInfo_OngoingGameevents.h"
#include "TXArtifactNegotiationEndEvent_RunInfo.generated.h"

USTRUCT(BlueprintType)
struct FTXArtifactNegotiationEndEvent_RunInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Duration;
    
    int32 team_level;
    int32 completed_stages;
    FTXArtifactNegotiationEndEvent_RunInfo_CurrentStage current_stage;
    FTXArtifactNegotiationEndEvent_RunInfo_OngoingGameevents ongoing_gameevents;
    ROGUECORE_API FTXArtifactNegotiationEndEvent_RunInfo();
};
