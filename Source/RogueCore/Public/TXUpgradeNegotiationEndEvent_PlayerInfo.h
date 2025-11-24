#pragma once
#include "CoreMinimal.h"
#include "TXUpgradeNegotiationEndEvent_PlayerInfo_Loadout.h"
#include "TXUpgradeNegotiationEndEvent_PlayerInfo_PlayerData.h"
#include "TXUpgradeNegotiationEndEvent_PlayerInfo_PlayerStats.h"
#include "TXUpgradeNegotiationEndEvent_PlayerInfo.generated.h"

USTRUCT(BlueprintType)
struct FTXUpgradeNegotiationEndEvent_PlayerInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 current_health;
    
    int32 max_health;
    int32 current_armor;
    int32 max_armor;
    FTXUpgradeNegotiationEndEvent_PlayerInfo_PlayerData player_data;
    FTXUpgradeNegotiationEndEvent_PlayerInfo_Loadout Loadout;
    TArray<FTXUpgradeNegotiationEndEvent_PlayerInfo_PlayerStats> player_stats;
    ROGUECORE_API FTXUpgradeNegotiationEndEvent_PlayerInfo();
};
