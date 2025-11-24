#pragma once
#include "CoreMinimal.h"
#include "TXUpgradeNegotiationEndEvent_RunInfo_OngoingGameevents_ObjectiveStates.h"
#include "TXUpgradeNegotiationEndEvent_RunInfo_OngoingGameevents_WaveStatus.h"
#include "TXUpgradeNegotiationEndEvent_RunInfo_OngoingGameevents.generated.h"

USTRUCT(BlueprintType)
struct FTXUpgradeNegotiationEndEvent_RunInfo_OngoingGameevents {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool is_elevator_called;
    
    bool is_risk_vector_screen;
    int32 time_since_last_negotiation;
    TArray<FTXUpgradeNegotiationEndEvent_RunInfo_OngoingGameevents_ObjectiveStates> objective_states;
    TArray<FTXUpgradeNegotiationEndEvent_RunInfo_OngoingGameevents_WaveStatus> wave_status;
    ROGUECORE_API FTXUpgradeNegotiationEndEvent_RunInfo_OngoingGameevents();
};
