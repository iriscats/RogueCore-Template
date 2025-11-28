#pragma once
#include "CoreMinimal.h"

#include "BeamSweepHitSignatureDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FBeamSweepHitSignature, FVector, HitLocation);
