#pragma once
#include "CoreMinimal.h"

#include "EventRewardSaveItem.generated.h"

USTRUCT(BlueprintType)
struct FEventRewardSaveItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid CategoryID;
    
    TArray<FGuid> ClassOptions;
    ROGUECORE_API FEventRewardSaveItem();
};
