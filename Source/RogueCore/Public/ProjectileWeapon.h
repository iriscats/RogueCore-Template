#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "ProjectileWeapon.generated.h"

class UProjectileLauncherComponent;
UCLASS(Blueprintable, NoExport)
class AProjectileWeapon : public AAmmoDrivenWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))

    UProjectileLauncherComponent* LauncherComponent;

    

    AProjectileWeapon(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProjectileLauncherComponent* LauncherComponent;
    
    AProjectileWeapon(const FObjectInitializer& ObjectInitializer);
};
