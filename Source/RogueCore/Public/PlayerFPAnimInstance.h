#pragma once
#include "CoreMinimal.h"

#include "PlayerAnimInstance.h"
#include "PlayerFPAnimInstance.generated.h"

class UAnimSequence;
UCLASS(Blueprintable, NonTransient)
class UPlayerFPAnimInstance : public UPlayerAnimInstance {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator WeaponRecoil;
    
    float HeadBobScale;
    float WeaponSwayRecoverySpeed;
    float WeaponSwayAlphaRecoverySpeed;
    FRotator WeaponSwayAngle;
    FRotator WeaponSwayAngleInverse;
    float WeaponSwayMaxAngle;
    FRotator CameraAntiSwayAngle;
    FRotator CameraAntiSwayAngleInverse;
    float WeaponSwayAlpha;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float WeaponSwayToApply;
    FVector CameraOffset;
    FVector NegativeCameraOffset;
    bool HeadOnlyMode;
    FRotator HeadRotation;
    UAnimSequence* FP_Idle;
    UAnimSequence* FP_Walk;
    UAnimSequence* FP_Sprint;
    UAnimSequence* FP_JumpStart;
    UAnimSequence* FP_JumpLoop;
    UAnimSequence* FP_JumpLand;
    UAnimSequence* FP_JumpLand_Aim;
    UAnimSequence* FP_Downed;
    UPlayerFPAnimInstance();
};
