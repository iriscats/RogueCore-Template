#pragma once
#include "CoreMinimal.h"
#include "DiscordUserInfoRequest.generated.h"

USTRUCT(BlueprintType)
struct FDiscordUserInfoRequest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString UserId;
    
    ROGUECORE_API FDiscordUserInfoRequest();
};
