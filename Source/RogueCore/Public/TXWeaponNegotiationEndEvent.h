#pragma once
#include "CoreMinimal.h"
#include "TXPlayerInfo.h"
#include "TXRunInfo.h"
#include "TXWeaponNegotiationEndEvent_Negotiation.h"
#include "TXWeaponNegotiationEndEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXWeaponNegotiationEndEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 player_count;
    
    FTXWeaponNegotiationEndEvent_Negotiation negotiation;
    FTXPlayerInfo player_info;
    FTXRunInfo run_info;
    ROGUECORE_API FTXWeaponNegotiationEndEvent();
};
