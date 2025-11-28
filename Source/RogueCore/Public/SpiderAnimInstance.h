#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EMoveDirection.h"
#include "ESpiderDeathAnimationCategory.h"
#include "EnemyAnimInstance.h"
#include "FootStepNotifyTarget.h"
#include "IKEffectorData.h"
#include "RandomWalkCycleEntry.h"
#include "SpiderAnimInstance.generated.h"

class UAnimMontage;
class UAnimSequenceBase;
class UEnemyPlaySoundKey;
class UEnemySpawnEffectsKey;
class UFXSystemAsset;
class USoundBase;
class USoundCue;
UCLASS(Blueprintable, NonTransient)
class USpiderAnimInstance : public UEnemyAnimInstance, public IFootStepNotifyTarget {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FIKEffectorData> IKEffectors;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Speed;
    FVector Velocity;
    float WalkCycleSpeed;
    float StartMovingSpeed;
    float StopMovingSpeed;
    float TurningAngularSpeed;
    float WalkCycleMinRate;
    float MinSpeedToOmniStrafe;
    float WalkCyclePlayRate;
    float TurnCyclePlayRate;
    float WalkCyclePlayRateExperimental;
    float MaxTurnRateForWalkCyclePlayRateExperimentalCalc;
    float MeshScale;
    float Direction;
    float PathDirectionLerpSpeedIn;
    float PathDirectionLerpSpeedOut;
    float PathDirection;
    float HorizontalAngularSpeed;
    float HorizontalAngularSpeed_Abs;
    float HorizontalAngularSpeedRaw;
    float VerticalAngularSpeed;
    float VerticalAngularSpeedRaw;
    float HorizontalStrafeSpeed;
    float VerticalStrafeSpeed;
    float VerticalStrafeOmni;
    float HorizontalStrafeOmni;
    float HorizontalAngleToWorldUp;
    float VerticalAngleToWorldUp;
    EMoveDirection MoveDirection;
    bool IsMoving;
    bool IsStrafing;
    bool IsMovingAndStrafing;
    bool IsFrozen;
    bool IsStaggered;
    float StaggerStrength;
    bool IsAirborne;
    UFXSystemAsset* FootStepParticle;
    USoundBase* FootStepSound;
    FName FootStepLeftBoneName;
    FName FootStepRightBoneName;
    float FootStepParticleCullDistance;
    TMap<UEnemyPlaySoundKey*, USoundCue*> PlaySoundByKeyMap;
    TMap<UEnemySpawnEffectsKey*, UFXSystemAsset*> SpawnEffectsByKeyMap;
    int32 RandomWalkCycleIndex;
    int32 RandomIdleCycle;
    int32 TotalRandomIdleCycles;
    TArray<FRandomWalkCycleEntry> RandomWalkCycles;
    bool TurnToIdle;
    bool IdleToTurnLeft;
    bool IdleToTurnRight;
    bool TurnToWalk;
    bool WalkToTurnRight;
    bool WalkToTurnLeft;
    bool ExclusiveTurnStateMode;
    bool IsInFakePhysics;
    UAnimMontage* SpawnMontage;
    ESpiderDeathAnimationCategory DeathAnimationCategory;
    float AimHorizontal;
    float AimVertical;
    USpiderAnimInstance(const FObjectInitializer& ObjectInitializer);
    USpiderAnimInstance();
    UFUNCTION(BlueprintCallable)
    void SetMeshScale(float NewScale);
    void SetDeathAnimationCategory(ESpiderDeathAnimationCategory Category);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SetDeathAnimation(UAnimSequenceBase* Animation);
    void PlayForcedCycle(float Duration);
    void OnMontageFinished(UAnimMontage* Montage, bool wasInterrupted);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTurningAndNotMoving() const;
    bool IsTurning() const;
    bool IsStrafingOrTurning() const;
    bool IsNotTurning() const;
    bool IsNotStrafing() const;
    bool IsNotStaggered() const;
    bool IsNotMoving() const;
    bool IsNotFrozen() const;
    bool IsNotAirborne() const;
    bool IsMovingOrTurning() const;
    bool GetIsMovingOrStrafing() const;
    // Fix for true pure virtual functions not being implemented
};
