#pragma once
#include "CoreMinimal.h"
#include "GetLobbiesResultDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FGetLobbiesResult, bool, success);
