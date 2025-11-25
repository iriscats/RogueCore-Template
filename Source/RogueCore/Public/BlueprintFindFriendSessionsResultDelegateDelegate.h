#pragma once
#include "CoreMinimal.h"
#include "Online/CoreOnline.h"
#include "FindSessionsCallbackProxy.h"
#include "SessionSearchResultTypes.h"
#include "BlueprintFindFriendSessionsResultDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBlueprintFindFriendSessionsResultDelegate, const TArray<FSessionSearchResultWrapper>&, Results);
