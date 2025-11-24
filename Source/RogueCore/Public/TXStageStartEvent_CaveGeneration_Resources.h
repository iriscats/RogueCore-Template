#pragma once
#include "CoreMinimal.h"
#include "TXStageStartEvent_CaveGeneration_Resources.generated.h"

USTRUCT(BlueprintType)
struct FTXStageStartEvent_CaveGeneration_Resources {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString resource_name;
    
    int32 target_amount;
    int32 spawned_amount;
    ROGUECORE_API FTXStageStartEvent_CaveGeneration_Resources();
};
