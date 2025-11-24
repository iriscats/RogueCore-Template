#pragma once
#include "CoreMinimal.h"
#include "CloudLoadRequest.generated.h"

USTRUCT(BlueprintType)
struct FCloudLoadRequest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SteamTicket;
    
    FString PSTicket;
    FString Branch;
    int32 Offset;
    ROGUECORE_API FCloudLoadRequest();
};
