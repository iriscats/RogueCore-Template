#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "PromotionRewardsSave.generated.h"

USTRUCT(BlueprintType)
struct FPromotionRewardsSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 PendingPromotionGifts;
    ROGUECORE_API FPromotionRewardsSave();
 
    TSet<FGuid> ClaimedRewards;
};
