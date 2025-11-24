#pragma once
#include "CoreMinimal.h"
#include "RunStatistics.generated.h"

USTRUCT(BlueprintType)
struct FRunStatistics {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CollectedExpenite;
    
    int32 RewardsAwarded;
    int32 ObjectivesCompleted;
    int32 ArtifactsCollected;
    int32 ArtifactsDispensed;
    int32 TotalArtifactGiversSpawned;
    int32 PotentExpeniteCollected;
    int32 PotentExpeniteDispensed;
    ROGUECORE_API FRunStatistics();
};
