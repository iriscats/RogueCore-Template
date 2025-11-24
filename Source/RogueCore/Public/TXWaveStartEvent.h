#pragma once
#include "CoreMinimal.h"
#include "TXPlayerInfo.h"
#include "TXRunInfo.h"
#include "TXWaveStartEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXWaveStartEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTXPlayerInfo player_info;
    
    FTXRunInfo run_info;
    ROGUECORE_API FTXWaveStartEvent();
};
