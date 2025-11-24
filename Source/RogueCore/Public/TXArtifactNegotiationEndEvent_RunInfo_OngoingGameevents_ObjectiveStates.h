#pragma once
#include "CoreMinimal.h"
#include "TXArtifactNegotiationEndEvent_RunInfo_OngoingGameevents_ObjectiveStates.generated.h"

USTRUCT(BlueprintType)
struct FTXArtifactNegotiationEndEvent_RunInfo_OngoingGameevents_ObjectiveStates {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    FString State;
    ROGUECORE_API FTXArtifactNegotiationEndEvent_RunInfo_OngoingGameevents_ObjectiveStates();
};
