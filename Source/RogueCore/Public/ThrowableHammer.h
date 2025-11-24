#pragma once
#include "CoreMinimal.h"
#include "ChargedWeapon.h"
#include "ThrowableHammer.generated.h"

class AHammerProjectile;
class URecallableProjectileComponent;
UCLASS(Blueprintable, NoExport)
class AThrowableHammer : public AChargedWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    AHammerProjectile* ThrownHammer;



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AHammerProjectile* ThrownHammer;
    
    bool HoldingUse;
    AThrowableHammer(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetThrownHammerProjectile(AHammerProjectile* Projectile);
    void CollectRecallable(URecallableProjectileComponent* RecallComponent);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_CollectRecallable(URecallableProjectileComponent* RecallComponent);
};
