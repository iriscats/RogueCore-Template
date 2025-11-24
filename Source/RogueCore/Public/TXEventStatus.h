#pragma once
#include "CoreMinimal.h"
#include "TXPlayerInfoStatus.h"
#include "TXRunInfoStatus.h"
#include "TXEventStatus.generated.h"

USTRUCT(BlueprintType)
struct FTXEventStatus {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 sec;
    
    FString gid;
    FString bid;
    FString pid;
    FString uid;
    FString run_guid;
    FTXRunInfoStatus run_info;
    FTXPlayerInfoStatus Player;
    ROGUECORE_API FTXEventStatus();
};
