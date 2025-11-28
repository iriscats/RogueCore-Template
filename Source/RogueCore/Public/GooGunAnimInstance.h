#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "GooGunAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UGooGunAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool isCharging;
    
    float ChargePercentVisual;
    float ChargePercent;
    float OverChargePercent;
    float BarrelRotationRate;
    UGooGunAnimInstance();
    UFUNCTION(BlueprintCallable)
    void SetTargetBarrelRotationRate(float RotationRate);
};
