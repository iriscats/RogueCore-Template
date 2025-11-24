#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EItemAimSetup.h"
#include "PlayerAnimInstance.h"
#include "PlayerTPAnimInstance.generated.h"

class UAnimSequence;
class UBlendSpace1D;
class UUpperBodyCharacterAnimationSet;
UCLASS(Blueprintable, NonTransient)
class UPlayerTPAnimInstance : public UPlayerAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UUpperBodyCharacterAnimationSet* UpperBodyCharacterSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RigidBodyBlend;
    bool RigidBodyOn;
    float UpperBodyBlend;
    float UpperBodyAnimationSetBlend;
    float AimingValue;
    EItemAimSetup TP_ItemAimSetup;
    bool TP_ForceAim;
    FRotator CounerMoveadjustmentAngleRotator;
    bool FullBodyAnimActive;
    float FullBodyBlendTime;
    float BodyTurnRecoverySpeed;
    float BodyTurnMaxAngle;
    float BodyTurnLerpEXP;
    float TurnAnimationDuration;
    bool bCaveLeechBiting;
    float CaveLeechBiteReactDelay;
    bool IsResettingBodyTurn;
    FRotator BodyTurn;
    FRotator BodyTurnLeft;
    FRotator BodyTurnRight;
    FRotator CounterBodyTurn;
    bool TurningLeft;
    bool TurningRight;
    float TurnProgress;
    float ItemIdleBlendTime;
    bool HasPickedUpItem;
    bool IsLyingDownNoTransition;
    int32 DanceMove;
    UAnimSequence* DanceSequence;
    bool IsDancing;
    float PickedUpItemBlend;
    float AttachedBodyTurnFactor;
    float AttachedHeadTurnFactor;
    FRotator AttachedBodyRotation;
    FRotator AttachedHeadRotation;
    UBlendSpace1D* TP_LookUpDown;
    UBlendSpace1D* TP_LookUpDown_Aim;
    UBlendSpace1D* A_TP_LookUpDown_Aim;
    UBlendSpace1D* B_TP_LookUpDown_Aim;
    UAnimSequence* TP_JumpLoop;
    UAnimSequence* TP_JumpLoop_Aim;
    UAnimSequence* TP_JumpStart;
    UAnimSequence* TP_JumpStart_Aim;
    UAnimSequence* TP_Sprint;
    UAnimSequence* A_TP_Idle;
    UAnimSequence* B_TP_Idle;
    UAnimSequence* A_TP_Idle_Aim;
    UAnimSequence* B_TP_Idle_Aim;
    UAnimSequence* TP_LookForward;
    UAnimSequence* A_TP_LookForward;
    UAnimSequence* B_TP_LookForward;
    UAnimSequence* A_TP_LookForward_Aim;
    UAnimSequence* B_TP_LookForward_Aim;
    UAnimSequence* A_TP_Walk_Forward;
    UAnimSequence* B_TP_Walk_Forward;
    UAnimSequence* A_TP_Run_Forward;
    UAnimSequence* B_TP_Run_Forward;
    UAnimSequence* A_TP_Walk_Forward_Aim;
    UAnimSequence* B_TP_Walk_Forward_Aim;
    UAnimSequence* A_TP_Run_Forward_Aim;
    UAnimSequence* B_TP_Run_Forward_Aim;
    UAnimSequence* A_TP_Walk_Right;
    UAnimSequence* B_TP_Walk_Right;
    UAnimSequence* A_TP_Run_Right;
    UAnimSequence* B_TP_Run_Right;
    UAnimSequence* A_TP_Walk_Right_Aim;
    UAnimSequence* B_TP_Walk_Right_Aim;
    UAnimSequence* A_TP_Run_Right_Aim;
    UAnimSequence* B_TP_Run_Right_Aim;
    UAnimSequence* A_TP_Walk_Left;
    UAnimSequence* B_TP_Walk_Left;
    UAnimSequence* A_TP_Run_Left;
    UAnimSequence* B_TP_Run_Left;
    UAnimSequence* A_TP_Walk_Left_Aim;
    UAnimSequence* B_TP_Walk_Left_Aim;
    UAnimSequence* A_TP_Run_Left_Aim;
    UAnimSequence* B_TP_Run_Left_Aim;
    UAnimSequence* A_TP_Walk_Back;
    UAnimSequence* B_TP_Walk_Back;
    UAnimSequence* A_TP_Run_Back;
    UAnimSequence* B_TP_Run_Back;
    UAnimSequence* A_TP_Walk_Back_Aim;
    UAnimSequence* B_TP_Walk_Back_Aim;
    UAnimSequence* A_TP_Run_Back_Aim;
    UAnimSequence* B_TP_Run_Back_Aim;
    UAnimSequence* TP_Revived;
    UAnimSequence* TP_Downed;
    UAnimSequence* TP_Downed_Loop;
    UAnimSequence* UB_Idle;
    UAnimSequence* UB_Jump;
    UAnimSequence* UB_Sprint;
    UAnimSequence* UB_Walk;
    UAnimSequence* UB_Run;
    UPlayerTPAnimInstance();
    UFUNCTION(BlueprintCallable)
    void SetOverrideFullBody(bool overrideEnabled);
};
