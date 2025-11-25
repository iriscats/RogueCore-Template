#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "ProjectileWeapon.generated.h"

class UProjectileLauncherComponent;
UCLASS(Blueprintable)
class AProjectileWeapon : public AAmmoDrivenWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProjectileLauncherComponent* LauncherComponent;
    
    AProjectileWeapon(const FObjectInitializer& ObjectInitializer);
};
