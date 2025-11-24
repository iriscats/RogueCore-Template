#pragma once
#include "CoreMinimal.h"
#include "CreditsReward.h"
#include "PendingRewardsStats.h"
#include "XPReward.h"
#include "PendingRewards.generated.h"

USTRUCT(BlueprintType)
struct FPendingRewards {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FPendingRewardsStats StartStats;
    
    FPendingRewardsStats EndStats;
    TArray<FCreditsReward> CreditsRewardEntries;
    int32 CreditsReward;
    TArray<FXPReward> XPRewardEntries;
    int32 XPReward;
    bool bHasData;
    bool bWasRewarded;
    ROGUECORE_API FPendingRewards();
};
