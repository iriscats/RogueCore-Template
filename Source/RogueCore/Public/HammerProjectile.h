#pragma once
#include "CoreMinimal.h"
#include "Projectile.h"
#include "HammerProjectile.generated.h"

UCLASS(Blueprintable)
class AHammerProjectile : public AProjectile {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Returning;
    
    AHammerProjectile(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StartReturnToPlayer();
};
