#pragma once
#include "CoreMinimal.h"
#include "AttackingPointInterface.h"
#include "DelegateDelegate.h"
#include "ETerminatorTentacleState.h"
#include "TentacleBase.h"
#include "TerminatorTarget.h"
#include "TriggerAI.h"
#include "TerminatorTentacle.generated.h"

class AActor;
class UAnimMontage;
class UAnimSequenceBase;
class UGrabberComponent;
class UHealthComponentBase;
class USkeletalMeshComponent;
UCLASS(Blueprintable)
class ROGUECORE_API ATerminatorTentacle : public ATentacleBase, public ITriggerAI, public IAttackingPointInterface {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnTentacleStateChangedEvent;
    
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimSequenceBase* FlairAnimation;
    float MinFlairAnimCooldown;
    float MaxFlairAnimationCooldown;
    float SwaySpeed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool Extended;
    TArray<UAnimMontage*> HitReactions;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_TentacleState, meta=(AllowPrivateAccess=true))
    ETerminatorTentacleState TentacleState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* HeadMesh;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGrabberComponent* GrabberComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_DesiredTarget, meta=(AllowPrivateAccess=true))
    FTerminatorTarget DesiredTarget;
    ATerminatorTentacle(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void PlayHitReaction(float amount);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStateChanged(ETerminatorTentacleState NewState);
    UFUNCTION()
    void OnRep_TentacleState();
    UFUNCTION()
    void OnRep_DesiredTarget();
    void OnHeadExitedTerrain();
    void OnHeadEnteredTerrain();
    void OnGrabbedActorReleased(AActor* Actor, bool fullGrabElapsed);
    void OnDeathEvent(UHealthComponentBase* EnemyHealth);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void MoveToGrabTarget(AActor* Target, float grabDuration);
    void ChangeTentacleState(ETerminatorTentacleState NewState);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_PlayFlairAnimation();
    // Fix for true pure virtual functions not being implemented
};
