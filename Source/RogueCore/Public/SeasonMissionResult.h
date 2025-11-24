#pragma once
#include "CoreMinimal.h"
#include "ChallengeInfo.h"
#include "SeasonEvent.h"
#include "SeasonMissionResult.generated.h"

class UTexture2D;
USTRUCT(BlueprintType)
struct FSeasonMissionResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 XPFromMission;
    
    int32 XPFromChallenges;
    int32 XPFromRewards;
    float XPMultiplier;
    int32 TokenGain;
    bool LevelIncreased;
    TArray<FChallengeInfo> UpdatedChallenges;
    TArray<FSeasonEvent> CompletedEvents;
    UTexture2D* EndScreenImage;
    UTexture2D* EndScreenResourceIcon;
    ROGUECORE_API FSeasonMissionResult();
};
