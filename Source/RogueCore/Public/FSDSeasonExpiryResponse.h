#pragma once
#include "CoreMinimal.h"
#include "FSDSeasonExpiryResponse.generated.h"

USTRUCT(BlueprintType)
struct FFSDSeasonExpiryResponse {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString SeasonExpirationTimeSteam;
    
    FString SeasonExpirationTimeSony;
    FString SeasonExpirationTimeGDK;
    ROGUECORE_API FFSDSeasonExpiryResponse();
};
