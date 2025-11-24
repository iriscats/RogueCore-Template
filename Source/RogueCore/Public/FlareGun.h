#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "FlareGun.generated.h"

UCLASS(Blueprintable, NoExport)
class AFlareGun : public AAmmoDrivenWeapon {
    GENERATED_BODY()
public:
    AFlareGun(const FObjectInitializer& ObjectInitializer);
};
