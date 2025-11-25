#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameSession.h"
#include "Engine/NetSerialization.h"
#include "FSDGameSession.generated.h"

UCLASS(Blueprintable)
class AFSDGameSession : public AGameSession {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnHostKickClient, const FString&, reason);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FUniqueNetIdRepl> KickedPlayers;
    TArray<FUniqueNetIdRepl> BannedPlayers;
    AFSDGameSession(const FObjectInitializer& ObjectInitializer);
};
