#pragma once
#include "CoreMinimal.h"
#include "TXTelemetryStateChangeEvent_Player.h"
#include "TXTelemetryStateChangeEvent_RunInfo.h"
#include "TXTelemetryStateChangeEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXTelemetryStateChangeEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString build_id;
    
    FString run_guid;
    FTXTelemetryStateChangeEvent_RunInfo run_info;
    FTXTelemetryStateChangeEvent_Player Player;
    FString game_id;
    FString platform_id;
    int32 sec;
    FString user_id;
    ROGUECORE_API FTXTelemetryStateChangeEvent();
};
