#pragma once
#include "CoreMinimal.h"
#include "Engine/NetSerialization.h"
#include "UsersChangedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FUsersChanged, const TArray<FUniqueNetIdRepl>&, userList);
