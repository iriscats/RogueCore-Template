#pragma once
#include "CoreMinimal.h"
#include "DiscordFactionRoleRequest.generated.h"

USTRUCT(BlueprintType)
struct FDiscordFactionRoleRequest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString UserId;
    
    int32 FactionID;
    FString SteamTicket;
    ROGUECORE_API FDiscordFactionRoleRequest();
};
