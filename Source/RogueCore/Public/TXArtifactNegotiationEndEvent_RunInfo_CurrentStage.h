#pragma once
#include "CoreMinimal.h"
#include "TXArtifactNegotiationEndEvent_RunInfo_CurrentStage.generated.h"

USTRUCT(BlueprintType)
struct FTXArtifactNegotiationEndEvent_RunInfo_CurrentStage {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Index;
    
    int32 Type;
    TArray<FString> enemy_pool;
    TArray<FString> risk_vectors;
    ROGUECORE_API FTXArtifactNegotiationEndEvent_RunInfo_CurrentStage();
};
