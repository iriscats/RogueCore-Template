#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Animation/AnimInstance.h"
#include "CryoSprayAnimInstance.generated.h"

class ACryosprayItem;
UCLASS(Blueprintable, NonTransient)
class UCryoSprayAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACryosprayItem* Weapon;
    
    bool IsFiring;
    float ChargeProgress;
    FRotator ChargeRotation;
    float ChargeBlend;
    float Pressure;
    UCryoSprayAnimInstance();
};
