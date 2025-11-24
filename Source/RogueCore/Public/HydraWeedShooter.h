#pragma once
#include "CoreMinimal.h"
#include "ShootingPlant.h"
#include "HydraWeedShooter.generated.h"

class AHydraWeedCore;
UCLASS(Blueprintable, NoExport)
class AHydraWeedShooter : public AShootingPlant {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AHydraWeedCore* Core;
    
    AHydraWeedShooter(const FObjectInitializer& ObjectInitializer);
};
