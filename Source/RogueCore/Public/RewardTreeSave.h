#pragma once
#include "CoreMinimal.h"
#include "RewardTreeSave.generated.h"

USTRUCT(BlueprintType)
struct FRewardTreeSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<int32, bool> NodesBought;
    
    ROGUECORE_API FRewardTreeSave();
};
