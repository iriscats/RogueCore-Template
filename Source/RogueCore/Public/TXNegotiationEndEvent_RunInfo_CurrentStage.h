#pragma once
#include "CoreMinimal.h"
#include "TXNegotiationEndEvent_RunInfo_CurrentStage.generated.h"

USTRUCT(BlueprintType)
struct FTXNegotiationEndEvent_RunInfo_CurrentStage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 stage_idx;
    
    FString stage_type;
    int32 stage_duration;
    int32 hostility_level;
    ROGUECORE_API FTXNegotiationEndEvent_RunInfo_CurrentStage();
};
