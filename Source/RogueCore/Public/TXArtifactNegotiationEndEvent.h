#pragma once
#include "CoreMinimal.h"
#include "TXArtifactNegotiationEndEvent_Negotiation.h"
#include "TXArtifactNegotiationEndEvent_PlayerInfo.h"
#include "TXArtifactNegotiationEndEvent_RunInfo.h"
#include "TXArtifactNegotiationEndEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXArtifactNegotiationEndEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 player_count;
    
    FTXArtifactNegotiationEndEvent_Negotiation negotiation;
    FTXArtifactNegotiationEndEvent_PlayerInfo player_info;
    FTXArtifactNegotiationEndEvent_RunInfo run_info;
    ROGUECORE_API FTXArtifactNegotiationEndEvent();
};
