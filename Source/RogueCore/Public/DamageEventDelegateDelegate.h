#pragma once
#include "CoreMinimal.h"
#include "DamageParams.h"
#include "DamageEventDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FDamageEventDelegate, float, damageDone, const FDamageParams&, Params);
