#pragma once
#include "CoreMinimal.h"
#include "TXLoadout.h"
#include "TXPlayerData.h"
#include "TXPlayerStat.h"
#include "TXPlayerInfo.generated.h"

USTRUCT(BlueprintType)
struct FTXPlayerInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 current_health;
    
    int32 max_health;
    int32 current_armor;
    int32 max_armor;
    FTXPlayerData player_data;
    FTXLoadout Loadout;
    TArray<FTXPlayerStat> player_stats;
    ROGUECORE_API FTXPlayerInfo();
};
