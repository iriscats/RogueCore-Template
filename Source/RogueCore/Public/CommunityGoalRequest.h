#pragma once
#include "CoreMinimal.h"
#include "CommunityGoalRequest.generated.h"

USTRUCT(BlueprintType)
struct FCommunityGoalRequest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString GoalID;
    
    int32 FactionID;
    float Value;
    FString SteamTicket;
    FString Branch;
    ROGUECORE_API FCommunityGoalRequest();
};
