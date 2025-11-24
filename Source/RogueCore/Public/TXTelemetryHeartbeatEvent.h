#pragma once
#include "CoreMinimal.h"
#include "TXTelemetryHeartbeatEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXTelemetryHeartbeatEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString aux;
    
    ROGUECORE_API FTXTelemetryHeartbeatEvent();
};
