#pragma once
#include "CoreMinimal.h"
#include "Online/CoreOnline.h"
#include "OnlineSubsystem.h"
#include "FindSessionsCallbackProxy.h"
#include "SessionSearchResultTypes.h"
#include "JoinSignatureDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FJoinSignature, FSessionSearchResultWrapper, Session);
