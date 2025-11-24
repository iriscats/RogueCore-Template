#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SpiderAnimInstance.h"
#include "PatrolBotAnimInstance.generated.h"

class APatrolBot;
UCLASS(Blueprintable, NonTransient)
class UPatrolBotAnimInstance : public USpiderAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APatrolBot* PatrolBot;
    
    FRotator TurretRotation;
    float Tilt;
    bool Rolling;
    bool NotRolling;
    bool Disabled;
    bool FlyingDisable;
    FRotator WheelRotation;
    FRotator WheelCenterRotation;
    FRotator FloatCenterRotation;
    float CurrentTilt;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TiltSpeed;
    float WheelSpeedModifier;
    UPatrolBotAnimInstance();
};
