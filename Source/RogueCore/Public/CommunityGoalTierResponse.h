#pragma once
#include "CoreMinimal.h"
#include "CommunityGoalTierResponse.generated.h"

USTRUCT(BlueprintType)
struct FCommunityGoalTierResponse {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Found;
    
    FString GoalID;
    float FirstTierGoal;
    float SecondTierGoal;
    float ThirdTierGoal;
    ROGUECORE_API FCommunityGoalTierResponse();
};
