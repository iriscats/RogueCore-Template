#pragma once
#include "CoreMinimal.h"
#include "Projectile.h"
#include "BoxProjectile.generated.h"

UCLASS(Blueprintable, NoExport)
class ABoxProjectile : public AProjectile {
    GENERATED_BODY()
public:
    ABoxProjectile(const FObjectInitializer& ObjectInitializer);
};
