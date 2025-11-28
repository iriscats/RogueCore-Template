#pragma once
#include "CoreMinimal.h"
#include "RewardsClaimed.generated.h"

USTRUCT(BlueprintType)
struct FRewardsClaimed {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool NormalClaimed;
    
    bool SpecialClaimed;
    ROGUECORE_API FRewardsClaimed();
};
