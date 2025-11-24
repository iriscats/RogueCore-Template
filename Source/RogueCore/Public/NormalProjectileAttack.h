#pragma once
#include "CoreMinimal.h"
#include "ProjectileAttack.h"
#include "Templates/SubclassOf.h"
#include "NormalProjectileAttack.generated.h"

class AProjectile;
UCLASS(Blueprintable, EditInlineNew)
class UNormalProjectileAttack : public UProjectileAttack {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AProjectile> Projectile;
    
    float RandomAngle;
    UNormalProjectileAttack();
};
