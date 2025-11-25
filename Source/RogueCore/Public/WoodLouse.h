#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "BumpPlayerHit.h"
#include "EWoodLouseState.h"
#include "EnemyDeepPathfinderCharacter.h"
#include "Templates/SubclassOf.h"
#include "WoodLouse.generated.h"

class AActor;
class APawn;
class AProjectile;
class UAudioComponent;
class UDamageClass;
class UFakeMoverSettings;
class USceneComponent;
class USoundBase;
class UStatusEffect;
UCLASS(Blueprintable, NoExport)
class AWoodLouse : public AEnemyDeepPathfinderCharacter {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* RollingCenter;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWoodLouseState forceState;
    float RollingCenterOffsetOnStanding;
    float RollingCenterOffsetOnFold;
    float ChanceToWalk;
    bool DebugAngle;
    UFakeMoverSettings* FakeMoverSettings;
    TSubclassOf<AProjectile> BurstProjectileClass;
    float BurstTime;
    TArray<TSubclassOf<UStatusEffect>> StatusEffectsOnRoll;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_LastHit, meta=(AllowPrivateAccess=true))
    FBumpPlayerHit LastHit;
    float TiltModifier;
    float BurstXOffset;
    float BurstYOffset;
    float BurstZOffset;
    float HighDifficultyCustomProjectileGravity;
    int32 BurstCount;
    bool InvounerableOnRoll;
    bool LockToRollMode;
    bool LockToWalkMode;
    float ForgetRange;
    float ForgetTime;
    float RefreshTimeMax;
    float RefreshTimeMin;
    float BumpPower;
    float DirectionalBumpPower;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EWoodLouseState CurrentState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AActor* CurrentTarget;
    float FoldedStateMaxTime;
    float FoldedStateMinTime;
    float UnfoldedStateMaxTime;
    float UnflodedStateMinTime;
    USoundBase* BumpSound;
    float TimeBetweenBumpingSamePlayer;
    float MinBumpDamage;
    float MaxBumpDamage;
    float BumpDamage;
    UDamageClass* BumpDamageType;
    float MaxBumpPower;
    float BumpRange;
    float AcceptableAngles;
    float RollSpeedModifier;
    float RollAlpha;
    float TiltAlpha;
    USoundBase* RollingSound;
    FName RollingSpeedParamName;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAudioComponent> RollingSoundComponent;
    UFakeMoverSettings* RollMoveSettings;
    UFakeMoverSettings* StopRollMoveSettings;
    FGameplayTagQuery TargetQuery;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool RotateTowardsTarget;
    float SeeTargetSafetyTime;
    bool WantsToStandUp;
    bool IsShooting;
    bool CanStandOnAnySurface;
    AWoodLouse(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SwitchedState(EWoodLouseState NewCurrentState);
    UFUNCTION(BlueprintCallable)
    void StopSpecial();
    void StartSpecial();
    void SetWantsToStandUp(bool aWantsToStandUp);
    void SetState(EWoodLouseState aState);
    void SetRotateToTarget(bool aRotateToTarget);
    void SeePawn(APawn* aSenPawn);
    UFUNCTION()
    void OnRep_State();
    UFUNCTION()
    void OnRep_LastHit();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EWoodLouseState GetRollerState() const;
    void BumpedTarget();
};
