#pragma once
#include "CoreMinimal.h"
#include "HostileTargetingGuntowerModule.h"
#include "Templates/SubclassOf.h"
#include "HomingFireModule.generated.h"

class AProjectile;
UCLASS(Blueprintable, NoExport)
class AHomingFireModule : public AHostileTargetingGuntowerModule {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ShootDroneSocket;
    
    TSubclassOf<AProjectile> HomingProjectileClass;
    float TimeBetweenShots;
    AHomingFireModule(const FObjectInitializer& ObjectInitializer);
};
