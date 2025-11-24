#pragma once
#include "CoreMinimal.h"
#include "OnRefreshPlayerDataTelemetryDelegate.generated.h"

class APlayerCharacter;
UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnRefreshPlayerDataTelemetry, APlayerCharacter*, Character);
