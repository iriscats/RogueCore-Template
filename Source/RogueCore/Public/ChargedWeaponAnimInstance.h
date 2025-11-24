#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ChargedWeaponAnimInstance.generated.h"

class AChargedWeapon;
UCLASS(Blueprintable, NonTransient)
class UChargedWeaponAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool isCharging;
    
    float ChargeupPlayRate;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ChargeupPlayRateSpeedChange;
    float ChargedownPlayRateSpeedChange;
    float MinChargeupPlayRate;
    float MaxChargeupPlayRate;
    AChargedWeapon* Weapon;
    UChargedWeaponAnimInstance();
};
