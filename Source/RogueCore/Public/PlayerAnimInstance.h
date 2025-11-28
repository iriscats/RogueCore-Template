#pragma once
#include "CoreMinimal.h"

#include "Animation/AnimInstance.h"
#include "ECharacterMoveDirection.h"
#include "ECharacterState.h"
#include "EGymAnimationState.h"
#include "FootStepNotifyTarget.h"
#include "GliderAnimSync.h"
#include "PlayerAnimInstance.generated.h"

class APlayerCharacter;
class UAnimMontage;
class UFXSystemAsset;
class UGymActivityProperties;
class UItemCharacterAnimationSet;
class USoundCue;
class UUseAnimationSetting;
UCLASS(Blueprintable, NonTransient)
class UPlayerAnimInstance : public UAnimInstance, public IFootStepNotifyTarget {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool IsFirstPerson;
    
    float WalkTreshhold;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* Character;
    UFXSystemAsset* DefaultFootstepParticle;
    USoundCue* DefaultFootStepSound;
    UItemCharacterAnimationSet* AnimationSetA;
    UItemCharacterAnimationSet* AnimationSetB;
    bool AnimationSetAIsPrimary;
    ECharacterState CharacterState;
    float Speed;
    float WalkAnimationSpeed;
    float RunAnimationSpeed;
    float WalkRate;
    float RunRate;
    float Direction;
    FRotator AimRotation;
    bool IsInitialized;
    float Pitch;
    bool IsStandingDown;
    bool IsInAir;
    bool IsMoving;
    bool IsWalking;
    bool IsSprinting;
    bool IsAiming;
    bool IsAlive;
    bool IsLyingDown;
    bool OnZipline;
    bool IsGrinding;
    bool IsParalyzed;
    bool IsSuspended;
    bool IsGrabbed;
    bool IsAttached;
    bool BeingRevived;
    bool IsLookingAtMap;
    bool IsControllingEnemy;
    bool IsUsingJetBoots;
    bool IsUsingTraversalTool;
    float TraversalToolTargetHorizontalOffset;
    float TraversalToolTargetVerticalOffset;
    float TraversalToolSpeedRate;
    FVector ControllingEnemyRootOffset;
    FVector ControllingEnemyDirectionAlpha;
    float GliderAnimationLength;
    FGliderAnimSync GliderAnimSync;
    bool IsAllowedToPlayMovementAnim;
    float CropBeard;
    UAnimMontage* ActiveUseMontage;
    UUseAnimationSetting* CurrentUseSetting;
    UAnimMontage* EndUseMontageToPlay;
    float AimDuration;
    float ReviveProgress;
    float ReviveExplicitTime;
    float IdleTimeForInspect;
    float RepeatDealayForInspect;
    ECharacterMoveDirection CharacterMoveDirection;
    float MoveAdjustmentAngle;
    UItemCharacterAnimationSet* CarryAnimationSet;
    UItemCharacterAnimationSet* DefaultAnimationSet;
    UPlayerAnimInstance();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateGymStressLevel(float StressLevel);
    void UpdateGymState(EGymAnimationState State);
    UFUNCTION(BlueprintCallable)
    bool StopUseMontage(bool stopImmediately);
    void StopInspectWeapon();
    void StartInspectWeapon();
    void SetAiming();
    void SendGymProperties(UGymActivityProperties* Properties);
    void PlayUseMontages(UUseAnimationSetting* useSetting);
    bool PlayCompletedUseMontage(UUseAnimationSetting* useSetting);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayingMontageInGroup(FName GroupName) const;
    APlayerCharacter* GetCharacter();
    UItemCharacterAnimationSet* GetAnimationSet() const;
    float CalculateDirectionVertical(const FVector& TargetDirection, const FRotator& BaseRotation) const;
    // Fix for true pure virtual functions not being implemented
};
