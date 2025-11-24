#pragma once
#include "CoreMinimal.h"
#include "RunRiskVector.h"
#include "RunSetup.h"
#include "RunState.generated.h"

USTRUCT(BlueprintType)
struct FRunState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRunSetup RunSetup;
    
    int32 ActiveStageIndex;
    TArray<int32> CompletedStages;
    TArray<FRunRiskVector> AdditionalRiskVectors;
    ROGUECORE_API FRunState();
};
