#pragma once
#include "CoreMinimal.h"
#include "CommunityGoalStateResponse.generated.h"

USTRUCT(BlueprintType)
struct FCommunityGoalStateResponse {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsGoal;
    
    bool IsRecruitment;
    bool FreeBeers;
    float TimeLeftSeconds;
    int32 LastUpdateGoalsID;
    int32 CurrentGoalPeriodID;
    ROGUECORE_API FCommunityGoalStateResponse();
};
