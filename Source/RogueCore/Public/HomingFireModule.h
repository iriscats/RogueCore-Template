#pragma once
#include "CoreMinimal.h"
#include "HostileTargetingGuntowerModule.h"
#include "Templates/SubclassOf.h"
#include "HomingFireModule.generated.h"

class AProjectile;
UCLASS(Blueprintable)
class AHomingFireModule : public AHostileTargetingGuntowerModule {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ShootDroneSocket;
    
    TSubclassOf<AProjectile> HomingProjectileClass;
    float TimeBetweenShots;
    AHomingFireModule(const FObjectInitializer& ObjectInitializer);
};
