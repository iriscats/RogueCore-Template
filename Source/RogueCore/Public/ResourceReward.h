#pragma once
#include "CoreMinimal.h"
#include "Reward.h"
#include "ResourceReward.generated.h"

class UResourceData;
UCLASS(Blueprintable, EditInlineNew)
class UResourceReward : public UReward {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UResourceData* Resource;
    
    int32 amount;
    UResourceReward();
};
