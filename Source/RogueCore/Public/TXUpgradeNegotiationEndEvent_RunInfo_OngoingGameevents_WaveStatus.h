#pragma once
#include "CoreMinimal.h"
#include "TXUpgradeNegotiationEndEvent_RunInfo_OngoingGameevents_WaveStatus.generated.h"

USTRUCT(BlueprintType)
struct FTXUpgradeNegotiationEndEvent_RunInfo_OngoingGameevents_WaveStatus {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Index;
    
    FString Trigger;
    FString ID;
    ROGUECORE_API FTXUpgradeNegotiationEndEvent_RunInfo_OngoingGameevents_WaveStatus();
};
