#pragma once
#include "CoreMinimal.h"
#include "TXTelemetryStartEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXTelemetryStartEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString aux;
    
    ROGUECORE_API FTXTelemetryStartEvent();
};
