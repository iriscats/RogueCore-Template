#pragma once
#include "CoreMinimal.h"
#include "ServerlistLobby.h"
#include "ServerListResponse.generated.h"

USTRUCT(BlueprintType)
struct FServerListResponse {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FServerlistLobby> Lobbies;
    
    ROGUECORE_API FServerListResponse();
};
