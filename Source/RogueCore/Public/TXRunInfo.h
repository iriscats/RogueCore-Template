#pragma once
#include "CoreMinimal.h"
#include "TXCurrentStage.h"
#include "TXOngoingGameevents.h"
#include "TXRunInfo.generated.h"

USTRUCT(BlueprintType)
struct FTXRunInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Duration;
    
    int32 team_level;
    int32 completed_stages;
    FTXCurrentStage current_stage;
    FTXOngoingGameevents ongoing_gameevents;
    ROGUECORE_API FTXRunInfo();
};
