#pragma once
#include "CoreMinimal.h"
#include "CloudSaveRequest.generated.h"

USTRUCT(BlueprintType)
struct FCloudSaveRequest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SteamTicket;
    
    FString PSTicket;
    int32 PlayerRank;
    int32 SaveToDiskCounter;
    FString RawData;
    FString Branch;
    ROGUECORE_API FCloudSaveRequest();
};
