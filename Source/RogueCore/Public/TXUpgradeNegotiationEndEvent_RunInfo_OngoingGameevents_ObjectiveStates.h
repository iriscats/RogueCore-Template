#pragma once
#include "CoreMinimal.h"
#include "TXUpgradeNegotiationEndEvent_RunInfo_OngoingGameevents_ObjectiveStates.generated.h"

USTRUCT(BlueprintType)
struct FTXUpgradeNegotiationEndEvent_RunInfo_OngoingGameevents_ObjectiveStates {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    FString State;
    ROGUECORE_API FTXUpgradeNegotiationEndEvent_RunInfo_OngoingGameevents_ObjectiveStates();
};
