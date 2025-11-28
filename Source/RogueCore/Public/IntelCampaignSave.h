#pragma once
#include "CoreMinimal.h"

#include "IntelCampaignSave.generated.h"

USTRUCT(BlueprintType)
struct FIntelCampaignSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 IntelPoints;
    
    TArray<FGuid> ClaimedObjectives;
    TArray<FGuid> ClaimedChallenges;
    TArray<FGuid> ChallengesThatCanBeClaimed;
    TMap<FGuid, float> StatsProgress;
    TSet<FGuid> NeutralizedEnemyTypes;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FGuid, float> StatsProgressInActiveRun;
    TArray<FGuid> WeaponsReceivedInActiveRun;
    ROGUECORE_API FIntelCampaignSave();
};
