#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "AmmoDrivenWeaponAnimInstance.generated.h"

class AAmmoDrivenWeapon;
UCLASS(Blueprintable, NonTransient)
class UAmmoDrivenWeaponAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAmmoDrivenWeapon* Weapon;
    
    bool IsFiring;
    float ClipFullPercentage;
    bool overheated;
    float temperature;
    UAmmoDrivenWeaponAnimInstance();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFull() const;
    bool IsEmpty() const;
};
