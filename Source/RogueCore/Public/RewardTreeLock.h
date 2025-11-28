#pragma once
#include "CoreMinimal.h"

#include "RewardTreeLock.generated.h"

USTRUCT(BlueprintType)
struct FRewardTreeLock {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 RequiredForUnlock;
    
    FVector2D position;
    ROGUECORE_API FRewardTreeLock();
};
