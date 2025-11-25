#pragma once
#include "CoreMinimal.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionInterface.h"
#include "Online/OnlineSessionSettings.h"
#include "FindSessionsCallbackProxy.h"
#include "JoinSignatureDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJoinSignature, FOnlineSessionSearchResult, Session);
