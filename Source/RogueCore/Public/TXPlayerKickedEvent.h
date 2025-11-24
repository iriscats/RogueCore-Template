#pragma once
#include "CoreMinimal.h"
#include "TXRunInfo.h"
#include "TXPlayerKickedEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXPlayerKickedEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool is_host;
    
    FString kick_reason;
    int32 player_count;
    FTXRunInfo run_info;
    ROGUECORE_API FTXPlayerKickedEvent();
};
