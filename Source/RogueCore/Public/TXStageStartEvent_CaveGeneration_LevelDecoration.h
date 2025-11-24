#pragma once
#include "CoreMinimal.h"
#include "TXNameAmountPair.h"
#include "TXStageStartEvent_CaveGeneration_LevelDecoration.generated.h"

USTRUCT(BlueprintType)
struct FTXStageStartEvent_CaveGeneration_LevelDecoration {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTXNameAmountPair> failures;
    
    TArray<FTXNameAmountPair> successes;
    ROGUECORE_API FTXStageStartEvent_CaveGeneration_LevelDecoration();
};
