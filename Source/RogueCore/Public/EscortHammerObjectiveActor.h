#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EEscortHammeState.h"
#include "EscortHammerMovementSetup.h"
#include "EscortHammerMovementState.h"
#include "EscortHammerObjectiveActor.generated.h"

class UPathfinderCollisionComponent;
class USceneComponent;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API AEscortHammerObjectiveActor : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_MovementState, meta=(AllowPrivateAccess=true))

    FEscortHammerMovementState MovementState;

    FEscortHammerMovementState LocalMovementState;

    AEscortHammerObjectiveActor(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* HammerRoot;
    
    USceneComponent* HammerMovementRoot;
    USceneComponent* HammerLocationStart;
    USceneComponent* HammerLocationEnd;
    USceneComponent* HammerPathfinderCollisionRoot;
    UPathfinderCollisionComponent* HammerPathfinderCollision;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EEscortHammeState, FEscortHammerMovementSetup> MovementSetups;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EEscortHammeState State;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_MovementState, meta=(AllowPrivateAccess=true))
    FEscortHammerMovementState MovementState;
    FEscortHammerMovementState LocalMovementState;
    AEscortHammerObjectiveActor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetHammerTargetVelocityMultiplier(float TargetVelocityMultiplier);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnVelocityChanged(float NewVelocity);
    void OnStateChanged(EEscortHammeState NewState, EEscortHammeState oldState);
    UFUNCTION(BlueprintCallable)
    void OnRep_State(EEscortHammeState prevState);
    UFUNCTION()
    void OnRep_MovementState();
    void OnMoved(float CurrentLocationPerc);
    void AdvanceState();
};
