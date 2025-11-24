#include "ProjectileWeapon.h"
#include "ProjectileLauncherComponent.h"

AProjectileWeapon::AProjectileWeapon(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LauncherComponent = CreateDefaultSubobject<UProjectileLauncherComponent>(TEXT("ProjectileLauncherComponent"));
}


