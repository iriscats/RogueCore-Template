#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeaponAnimInstance.h"
#include "PlatformGunAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UPlatformGunAnimInstance : public UAmmoDrivenWeaponAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))

    float NormalSpinRate;

    float LerpSpeed;

    float FiredSpinRate;

    UPlatformGunAnimInstance();

    UFUNCTION(BlueprintCallable)

    void WeaponFired();



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float SpinRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float NormalSpinRate;
    float LerpSpeed;
    float FiredSpinRate;
    UPlatformGunAnimInstance();
    UFUNCTION(BlueprintCallable)
    void WeaponFired();
};
