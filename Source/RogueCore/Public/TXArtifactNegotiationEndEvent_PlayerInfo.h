#pragma once
#include "CoreMinimal.h"
#include "TXArtifactNegotiationEndEvent_PlayerInfo_Loadout.h"
#include "TXArtifactNegotiationEndEvent_PlayerInfo_PlayerData.h"
#include "TXArtifactNegotiationEndEvent_PlayerInfo_PlayerStats.h"
#include "TXArtifactNegotiationEndEvent_PlayerInfo.generated.h"

USTRUCT(BlueprintType)
struct FTXArtifactNegotiationEndEvent_PlayerInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 current_health;
    
    int32 max_health;
    int32 current_armor;
    int32 max_armor;
    FTXArtifactNegotiationEndEvent_PlayerInfo_PlayerData player_data;
    FTXArtifactNegotiationEndEvent_PlayerInfo_Loadout Loadout;
    TArray<FTXArtifactNegotiationEndEvent_PlayerInfo_PlayerStats> player_stats;
    ROGUECORE_API FTXArtifactNegotiationEndEvent_PlayerInfo();
};
