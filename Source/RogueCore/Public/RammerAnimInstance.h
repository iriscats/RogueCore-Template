#pragma once
#include "CoreMinimal.h"
#include "SpiderAnimInstance.h"
#include "RammerAnimInstance.generated.h"

class UCarveChargeComponent;
UCLASS(Blueprintable, NonTransient)
class ROGUECORE_API URammerAnimInstance : public USpiderAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCarveChargeComponent* CachedChargeComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Acceleration;
    float InterpolatedAcceleration;
    float AccelerationInterpolationWeight;
    bool IsTelegraphing;
    bool isCharging;
    float ChargeSpeed;
    float HorizontalAngularChargeSpeed;
    float VerticalAngularChargeSpeed;
    bool HasCarvedRecently;
    bool IsStoppingEarly;
    URammerAnimInstance();
};
