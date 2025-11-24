#pragma once
#include "CoreMinimal.h"
#include "TXNegotiationData.h"
#include "TXPlayerInfo.h"
#include "TXRunEndEvent_Enhancements.h"
#include "TXRunEndEvent_Loot.h"
#include "TXRunInfo.h"
#include "TXRunEndEvent.generated.h"

USTRUCT(BlueprintType)
struct FTXRunEndEvent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 player_count;
    
    FString Result;
    bool disbanded_by_host;
    FTXRunEndEvent_Enhancements Enhancements;
    FTXNegotiationData negotiations;
    FTXRunEndEvent_Loot loot;
    FTXPlayerInfo player_info;
    FTXRunInfo run_info;
    ROGUECORE_API FTXRunEndEvent();
};
