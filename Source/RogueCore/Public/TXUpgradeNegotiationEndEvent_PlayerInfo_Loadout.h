#pragma once
#include "CoreMinimal.h"
#include "TXUpgradeNegotiationEndEvent_PlayerInfo_Loadout_Items.h"
#include "TXUpgradeNegotiationEndEvent_PlayerInfo_Loadout_NegotiatedUnlocks.h"
#include "TXUpgradeNegotiationEndEvent_PlayerInfo_Loadout_PersonalUnlocks.h"
#include "TXUpgradeNegotiationEndEvent_PlayerInfo_Loadout.generated.h"

USTRUCT(BlueprintType)
struct FTXUpgradeNegotiationEndEvent_PlayerInfo_Loadout {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTXUpgradeNegotiationEndEvent_PlayerInfo_Loadout_Items> Items;
    
    TArray<FTXUpgradeNegotiationEndEvent_PlayerInfo_Loadout_PersonalUnlocks> personal_unlocks;
    TArray<FTXUpgradeNegotiationEndEvent_PlayerInfo_Loadout_NegotiatedUnlocks> negotiated_unlocks;
    TArray<FString> artifacts;
    ROGUECORE_API FTXUpgradeNegotiationEndEvent_PlayerInfo_Loadout();
};
