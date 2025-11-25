#pragma once
#include "CoreMinimal.h"
#include "Online/CoreOnline.h"
#include "FindSessionsCallbackProxy.h"
#include "SessionSearchResultTypes.h"
#include "BlueprintRegisterSessionInviteNotificationDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBlueprintRegisterSessionInviteNotificationDelegate, const FSessionSearchResultWrapper&, SessionInvite);
