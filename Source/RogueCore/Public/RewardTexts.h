#pragma once
#include "CoreMinimal.h"
#include "RewardTexts.generated.h"

USTRUCT(BlueprintType)
struct FRewardTexts {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText StagesCleared;
    
    FText PrimaryObjective;
    FText SecondaryObjective;
    FText CountPrimaryObjectives;
    FText CountSecondaryObjectives;
    FText MineralsMinedByTeam;
    FText HostilesKilled;
    ROGUECORE_API FRewardTexts();
};
