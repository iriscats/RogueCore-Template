#pragma once
#include "CoreMinimal.h"
#include "TXUpgradeNegotiationEndEvent_Negotiation.h"
#include "TXUpgradeNegotiationEndEvent_PlayerInfo.h"
#include "TXUpgradeNegotiationEndEvent_RunInfo.h"
#include "TXUpgradeNegotiationEndEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXUpgradeNegotiationEndEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 player_count;
    
    FTXUpgradeNegotiationEndEvent_Negotiation negotiation;
    FTXUpgradeNegotiationEndEvent_PlayerInfo player_info;
    FTXUpgradeNegotiationEndEvent_RunInfo run_info;
    ROGUECORE_API FTXUpgradeNegotiationEndEvent();
};
