#pragma once
#include "CoreMinimal.h"

#include "OnProjectileImpactDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnProjectileImpactDelegate, bool, isPredictedImpact, const FHitResult&, HitResult);
