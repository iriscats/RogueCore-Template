#pragma once
#include "CoreMinimal.h"
#include "RegisterSessionRequest.generated.h"

USTRUCT(BlueprintType)
struct FRegisterSessionRequest {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString ServerName;
    
    int32 NumPlayers;
    FString LobbyId;
    FString P2PADDR;
    int32 P2PPORT;
    ROGUECORE_API FRegisterSessionRequest();
};
