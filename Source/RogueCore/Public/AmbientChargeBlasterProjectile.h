#pragma once
#include "CoreMinimal.h"
#include "Projectile.h"
#include "AmbientChargeBlasterProjectile.generated.h"

class UDamageAsset;
UCLASS(Blueprintable)
class ROGUECORE_API AAmbientChargeBlasterProjectile : public AProjectile {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageAsset* DamageAsset;

 
    AAmbientChargeBlasterProjectile(const FObjectInitializer& ObjectInitializer);
};
