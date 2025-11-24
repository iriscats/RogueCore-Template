#pragma once
#include "CoreMinimal.h"
#include "TXTelemetryStateChangeEvent_RunInfo.generated.h"

USTRUCT(BlueprintType)
struct FTXTelemetryStateChangeEvent_RunInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString run_name;
    
    int32 run_depth;
    int32 run_seed;
    ROGUECORE_API FTXTelemetryStateChangeEvent_RunInfo();
};
