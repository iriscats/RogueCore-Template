#pragma once
#include "CoreMinimal.h"
#include "TXNegotiationEndEvent_Character.h"
#include "TXNegotiationEndEvent_Loadout.h"
#include "TXNegotiationEndEvent_Negotiation.h"
#include "TXNegotiationEndEvent_RunInfo.h"
#include "TXNegotiationEndEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXNegotiationEndEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 player_count;
    
    int32 stage_index;
    FTXNegotiationEndEvent_Loadout Loadout;
    FTXNegotiationEndEvent_Character Character;
    FTXNegotiationEndEvent_RunInfo run_info;
    FTXNegotiationEndEvent_Negotiation negotiation;
    ROGUECORE_API FTXNegotiationEndEvent();
};
