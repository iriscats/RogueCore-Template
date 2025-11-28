#pragma once
#include "CoreMinimal.h"
#include "Online/CoreOnline.h"
#include "SessionSearchResultTypes.h"

#include "Subsystems/GameInstanceSubsystem.h"
#include "GetLobbiesResultDelegate.h"
#include "ServerlistLobby.h"
#include "FindSessionsCallbackProxy.h"
#include "FSDServerListClient.generated.h"

UCLASS(Blueprintable)
class UFSDServerListClient : public UGameInstanceSubsystem {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBlueprintFindSessionsResultDelegate, const TArray<FSessionSearchResultWrapper>&, Results);

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FServerlistLobby> Lobbies;
    FServerlistLobby MyActiveLobbyData;
    FGuid LobbyGuid;
    FString FilterRunName;
    bool IsInProgress;
    FString CurrentSessionId;

    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGetLobbiesResult ListDelegate;
    UFSDServerListClient();
    UFUNCTION(BlueprintCallable)
    bool StopHosting();
    bool StartHosting(const FString& RunName);
    void ListLobbys();
    FSessionSearchResultWrapper CreateSessionData(FServerlistLobby FromLobby);
    int32 CalculateRemoteServerPing(const FString& RemoteServerSteamLocation);
};
