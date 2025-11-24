#pragma once
#include "CoreMinimal.h"
#include "Projectile.h"
#include "HammerProjectile.generated.h"

UCLASS(Blueprintable, NoExport)
class AHammerProjectile : public AProjectile {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Returning;
    
    AHammerProjectile(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StartReturnToPlayer();
};
