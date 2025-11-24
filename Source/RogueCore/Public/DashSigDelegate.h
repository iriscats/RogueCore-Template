#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DashSigDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDashSig, FVector, Direction);
