#pragma once
#include "CoreMinimal.h"
#include "ForgingPendingReward.h"
#include "ForgingSave.generated.h"

USTRUCT(BlueprintType)
struct FForgingSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 XP;
    TArray<FForgingPendingReward> PendingMasteryRewards;
    ROGUECORE_API FForgingSave();
 
};
