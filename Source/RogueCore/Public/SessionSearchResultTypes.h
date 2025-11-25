#pragma once
#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "SessionSearchResultTypes.generated.h"

// Use FString as a handle/container for the session data
// This avoids needing the full FOnlineSessionSearchResult definition in headers

USTRUCT(BlueprintType)
struct FSessionSearchResultWrapper
{
	GENERATED_BODY()

	// Store the session ID as a string - accessible from Blueprints
	UPROPERTY(BlueprintReadOnly)
	FString SessionId;

	// Ping in milliseconds
	UPROPERTY(BlueprintReadOnly)
	int32 PingInMs;

	// Server name
	UPROPERTY(BlueprintReadOnly)
	FString ServerName;

	// Current players
	UPROPERTY(BlueprintReadOnly)
	int32 CurrentPlayers;

	// Max players
	UPROPERTY(BlueprintReadOnly)
	int32 MaxPlayers;

	ROGUECORE_API FSessionSearchResultWrapper()
		: PingInMs(9999)
		, CurrentPlayers(0)
		, MaxPlayers(0)
	{}
};
