#pragma once
#include "CoreMinimal.h"
#include "MilestoneCounter.h"
#include "MilestoneSave.generated.h"

USTRUCT(BlueprintType)
struct FMilestoneSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMilestoneCounter> ClaimedKPIRewards;
    ROGUECORE_API FMilestoneSave();
 
};
