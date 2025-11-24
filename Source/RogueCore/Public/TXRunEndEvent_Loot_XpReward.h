#pragma once
#include "CoreMinimal.h"
#include "TXRunEndEvent_Loot_XpReward.generated.h"

USTRUCT(BlueprintType)
struct FTXRunEndEvent_Loot_XpReward {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    int32 amount;
    int32 xp_reward;
    ROGUECORE_API FTXRunEndEvent_Loot_XpReward();
};
