#pragma once
#include "CoreMinimal.h"
#include "RunHistoryBasicCharacterStats.h"
#include "RunHistoryBasicCooperStats.h"
#include "SharedRunData.generated.h"

USTRUCT(BlueprintType)
struct ROGUECORE_API FSharedRunData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 CompletedStages;
    
    bool MissionSuccess;
    int32 Year;
    uint8 Month;
    uint8 Day;
    uint8 LocalCharacterIndex;
    TArray<FRunHistoryBasicCharacterStats> BasicCharacterStats;
    FRunHistoryBasicCooperStats BasicCooperStats;
    FSharedRunData();
};
