#pragma once
#include "CoreMinimal.h"
#include "TXStageStartEvent_CaveGeneration_Biome_Features.h"
#include "TXStageStartEvent_CaveGeneration_Biome.generated.h"

USTRUCT(BlueprintType)
struct FTXStageStartEvent_CaveGeneration_Biome {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Name;
    
    TArray<FTXStageStartEvent_CaveGeneration_Biome_Features> features;
    ROGUECORE_API FTXStageStartEvent_CaveGeneration_Biome();
};
