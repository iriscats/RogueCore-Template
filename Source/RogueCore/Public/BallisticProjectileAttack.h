#pragma once
#include "CoreMinimal.h"
#include "ProjectileAttack.h"
#include "Templates/SubclassOf.h"
#include "BallisticProjectileAttack.generated.h"

class AProjectile;
UCLASS(Blueprintable, EditInlineNew)
class UBallisticProjectileAttack : public UProjectileAttack {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AProjectile> Projectile;
    
    float ProjectileArc;
    float Gravity;
    UBallisticProjectileAttack();
};
