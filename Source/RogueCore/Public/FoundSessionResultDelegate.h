#pragma once
#include "CoreMinimal.h"
#include "OnlineSubsystem.h"
#include "OnlineSessionInterface.h"
#include "FindSessionsCallbackProxy.h"
#include "Online/OnlineSessionSettings.h"
#include "FoundSessionResultDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFoundSessionResult, FOnlineSessionSearchResult, Result);
