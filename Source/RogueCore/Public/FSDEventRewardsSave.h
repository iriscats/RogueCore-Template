#pragma once
#include "CoreMinimal.h"

#include "FSDEventRewardsSave.generated.h"

USTRUCT(BlueprintType)
struct FFSDEventRewardsSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSet<FGuid> EventsSeen;

    TSet<FGuid> PopupsSeen;
    ROGUECORE_API FFSDEventRewardsSave();
 
};
