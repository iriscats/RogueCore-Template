#pragma once
#include "CoreMinimal.h"
#include "ChargedWeaponAnimInstance.h"
#include "CoilGunAnimInstance.generated.h"

class ACoilGun;
UCLASS(Blueprintable, NonTransient)
class UCoilGunAnimInstance : public UChargedWeaponAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WindUpSpeed;
    
    float WindDownSpeed;
    float MaxExtention;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float HandleExtend;
    float MaxCoilSpeed;
 
    ACoilGun* CoilGun;
    UCoilGunAnimInstance();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCoilSpeed(int32 Index) const;
    float GetCoilAngle(int32 Index) const;
};
