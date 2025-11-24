#pragma once
#include "CoreMinimal.h"
#include "TXRunEndEvent_Loot_XpReward.h"
#include "TXRunEndEvent_Loot.generated.h"

USTRUCT(BlueprintType)
struct FTXRunEndEvent_Loot {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTXRunEndEvent_Loot_XpReward> xp_reward;
    
    int32 total_xp_reward;
    int32 pp_reward;
    ROGUECORE_API FTXRunEndEvent_Loot();
};
