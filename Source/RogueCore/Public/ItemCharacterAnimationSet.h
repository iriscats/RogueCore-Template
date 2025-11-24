#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "EItemAimSetup.h"
#include "ItemLoadoutAnimations.h"
#include "ItemCharacterAnimationSet.generated.h"

class UAnimMontage;
class UAnimSequence;
class UBlendSpace1D;
class UItemCharacterAnimationSet;
UCLASS(Blueprintable)
class UItemCharacterAnimationSet : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequence* FP_Idle;
    
    UAnimMontage* FP_InspectWeapon;
    UAnimSequence* FP_Walk;
    UAnimSequence* FP_Sprint;
    UAnimSequence* FP_JumpStart;
    UAnimSequence* FP_JumpLoop;
    UAnimSequence* FP_JumpLand;
    UAnimSequence* FP_JumpLand_Aim;
    UAnimSequence* FP_Downed;
    UBlendSpace1D* TP_LookUpDown;
    UBlendSpace1D* TP_LookUpDown_Aim;
    UAnimSequence* TP_Sprint;
    UAnimSequence* TP_Idle;
    UAnimSequence* TP_Idle_Aim;
    UAnimSequence* TP_LookForward;
    UAnimSequence* TP_LookForward_Aim;
    UAnimSequence* TP_JumpStart;
    UAnimSequence* TP_JumpStart_Aim;
    UAnimSequence* TP_JumpLoop;
    UAnimSequence* TP_JumpLoop_Aim;
    UAnimMontage* TP_JumpLand;
    UAnimSequence* TP_Walk_Forward;
    UAnimSequence* TP_Walk_Forward_Aim;
    UAnimSequence* TP_Run_Forward;
    UAnimSequence* TP_Run_Forward_Aim;
    UAnimSequence* TP_Walk_Right;
    UAnimSequence* TP_Walk_Right_Aim;
    UAnimSequence* TP_Run_Right;
    UAnimSequence* TP_Run_Right_Aim;
    UAnimSequence* TP_Walk_Left;
    UAnimSequence* TP_Walk_Left_Aim;
    UAnimSequence* TP_Run_Left;
    UAnimSequence* TP_Run_Left_Aim;
    UAnimSequence* TP_Walk_Back;
    UAnimSequence* TP_Walk_Back_Aim;
    UAnimSequence* TP_Run_Back;
    UAnimSequence* TP_Run_Back_Aim;
    UAnimSequence* TP_Revived;
    UAnimSequence* TP_Downed;
    UAnimSequence* TP_Downed_Loop;
    EItemAimSetup TP_ItemAimSetup;
    bool TP_AlwaysAim;
    FItemLoadoutAnimations LoadoutAnimations;
    float CameraOffset;
    UItemCharacterAnimationSet* ParentSet;
    UItemCharacterAnimationSet();
};
