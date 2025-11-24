#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ChallengeSaveInfo.h"
#include "RewardsClaimed.h"
#include "SeasonSaveEntry.generated.h"

USTRUCT(BlueprintType)
struct FSeasonSaveEntry {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 XP;
    
    int32 Tokens;
    TArray<FRewardsClaimed> RewardsClaimed;
    bool HasClaimedAllRewards;
    int32 RewardsClaimedAfterMaxLevel;
    TMap<int32, bool> NodesBought;
    TArray<FChallengeSaveInfo> ActiveChallenges;
    FDateTime LastNewChallengeGiven;
    FDateTime LastChallengeReroll;
    TMap<FGuid, int32> CompletedSpecialChallenges;
    int32 ClaimedScripChallenges;
    int32 PlagueHeartsUsed;
    float TimePlayedAtSeasonStart;
    float ChallengesCompletedAtSeasonStart;
    ROGUECORE_API FSeasonSaveEntry();
};
