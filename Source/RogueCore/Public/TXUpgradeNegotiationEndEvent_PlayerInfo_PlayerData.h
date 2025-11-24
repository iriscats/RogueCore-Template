#pragma once
#include "CoreMinimal.h"
#include "TXUpgradeNegotiationEndEvent_PlayerInfo_PlayerData.generated.h"

USTRUCT(BlueprintType)
struct FTXUpgradeNegotiationEndEvent_PlayerInfo_PlayerData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 kills;
    
    int32 deaths;
    int32 revives;
    int32 mined;
    int32 damage_dealt;
    int32 damage_taken;
    ROGUECORE_API FTXUpgradeNegotiationEndEvent_PlayerInfo_PlayerData();
};
