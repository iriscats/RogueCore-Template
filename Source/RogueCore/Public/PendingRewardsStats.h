#pragma once
#include "CoreMinimal.h"
#include "PendingRewardsStats.generated.h"

class UResourceData;
USTRUCT(BlueprintType)
struct FPendingRewardsStats {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<UResourceData*, float> AllResources;
    
    TMap<UResourceData*, float> CollectedResources;
    bool PrimaryObjectiveCompleted;
    bool SecondaryObjectiveCompleted;
    float TimePlayed;
    int32 EnemiesKilled;
    ROGUECORE_API FPendingRewardsStats();
};
