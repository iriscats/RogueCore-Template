#pragma once
#include "CoreMinimal.h"
#include "TXArtifactNegotiationEndEvent_RunInfo_OngoingGameevents_ObjectiveStates.h"
#include "TXArtifactNegotiationEndEvent_RunInfo_OngoingGameevents_WaveStatus.h"
#include "TXArtifactNegotiationEndEvent_RunInfo_OngoingGameevents.generated.h"

USTRUCT(BlueprintType)
struct FTXArtifactNegotiationEndEvent_RunInfo_OngoingGameevents {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool is_elevator_called;
    
    bool is_risk_vector_screen;
    int32 time_since_last_negotiation;
    TArray<FTXArtifactNegotiationEndEvent_RunInfo_OngoingGameevents_ObjectiveStates> objective_states;
    TArray<FTXArtifactNegotiationEndEvent_RunInfo_OngoingGameevents_WaveStatus> wave_status;
    ROGUECORE_API FTXArtifactNegotiationEndEvent_RunInfo_OngoingGameevents();
};
