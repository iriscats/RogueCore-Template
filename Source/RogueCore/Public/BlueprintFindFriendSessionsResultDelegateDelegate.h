#pragma once
#include "CoreMinimal.h"
#include "FindSessionsCallbackProxy.h"
#include "OnlineSessionInterface.h"
#include "Online/OnlineSessionSettings.h"
#include "BlueprintFindFriendSessionsResultDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBlueprintFindFriendSessionsResultDelegate, const TArray<FOnlineSessionSearchResult>&, Results);
