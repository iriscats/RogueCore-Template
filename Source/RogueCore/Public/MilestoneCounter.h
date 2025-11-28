#pragma once
#include "CoreMinimal.h"

#include "MilestoneCounter.generated.h"

USTRUCT(BlueprintType)
struct FMilestoneCounter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid KPIGuid;
    
    int32 Tier;
    ROGUECORE_API FMilestoneCounter();
};
