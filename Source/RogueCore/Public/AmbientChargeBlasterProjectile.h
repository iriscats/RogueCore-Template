#pragma once
#include "CoreMinimal.h"
#include "Projectile.h"
#include "AmbientChargeBlasterProjectile.generated.h"

class UDamageAsset;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API AAmbientChargeBlasterProjectile : public AProjectile {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageAsset* DamageAsset;

 
    AAmbientChargeBlasterProjectile(const FObjectInitializer& ObjectInitializer);
};
