#pragma once
#include "CoreMinimal.h"
#include "Online/CoreOnline.h"
#include "OnlineSubsystem.h"
#include "SessionSearchResultTypes.h"
#include "FoundSessionResultDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FFoundSessionResult, FSessionSearchResultWrapper, Result);
