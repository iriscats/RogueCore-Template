#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DeepPathfinderCharacter.h"
#include "ERecallableActorState.h"
#include "ReturnedSignatureDelegate.h"
#include "Templates/SubclassOf.h"
#include "Upgradable.h"
#include "RecallableActor.generated.h"

class AActor;
class ARecallableActor;
UCLASS(Abstract, Blueprintable)
class ARecallableActor : public ADeepPathfinderCharacter, public IUpgradable {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FRecallableActorStateChanged, ARecallableActor*, Sender, ERecallableActorState, State);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRecallableActorStateChanged OnStateChanged;
    FReturnedSignature OnReturnFinish;
    FReturnedSignature OnRelocateFinished;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AcceptanceRadius;
    float AutoRecallDistance;
    float RelocateLandingHeight;
    TSubclassOf<AActor> RelocationMarkerType;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_RecallTarget, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> RecallTarget;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    ERecallableActorState State;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTransform RelocateTransform;
    bool RelocateLanded;
    TWeakObjectPtr<AActor> RelocationMarker;
    bool bInitialized;
    ARecallableActor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void SetRecallTarget(AActor* NewTarget);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Relocate(FVector NewLocation, FRotator NewRotation);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveOnStateChanged();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Recall();
    void OnReturnSucceeded();
    void OnReturnFailed();
    UFUNCTION(BlueprintCallable)
    void OnRep_State(ERecallableActorState oldState);
    UFUNCTION()
    void OnRep_RecallTarget();
    void OnRelocated();
    void OnRecallTargetChanged(AActor* NewTarget);
    void OnPathFinished(bool success);
    void OnMoving();
    void OnMoveRequested();
    void OnMoveFinished(bool returnedHome);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsReturning() const;
    bool GetIsMovingOrMoveRequested() const;
    bool GetIsMoving() const;
    bool GetIsMoveRequested() const;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void BeginMove();
    // Fix for true pure virtual functions not being implemented
};
