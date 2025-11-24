#pragma once
#include "CoreMinimal.h"
#include "TXPlayerInfo.h"
#include "TXRiskvectorNegotiationEndEvent_Negotiation.h"
#include "TXRunInfo.h"
#include "TXRiskvectorNegotiationEndEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXRiskvectorNegotiationEndEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 player_count;
    
    FTXRiskvectorNegotiationEndEvent_Negotiation negotiation;
    FTXPlayerInfo player_info;
    FTXRunInfo run_info;
    ROGUECORE_API FTXRiskvectorNegotiationEndEvent();
};
