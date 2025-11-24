#pragma once
#include "CoreMinimal.h"
#include "ServerlistLobby.generated.h"

USTRUCT(BlueprintType)
struct FServerlistLobby {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString RunName;
    
    bool IsInProgress;
    FString ServerName;
    FString SanitizedServerName;
    int32 NumPlayers;
    bool IsFull;
    FString Region;
    TArray<int32> Classes;
    bool IsClassLocked;
    bool PasswordProtected;
    FString SessionId;
    int32 GameVersion;
    FString PingLocation;
    FString HostUserID;
    ROGUECORE_API FServerlistLobby();
};
