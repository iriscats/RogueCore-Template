#pragma once
#include "CoreMinimal.h"

#include "AFlyingBug.h"
#include "EGrabberState.h"
#include "GrabSuccessDelegate.h"
#include "FlyingLifter.generated.h"

class AActor;
class UAnimSequenceBase;
class UAudioComponent;
class UCapsuleComponent;
class UGrabberComponent;
class UInDangerComponent;
class UPointLightComponent;
class UPrimitiveComponent;
class USoundBase;
UCLASS(Abstract, Blueprintable, NoExport)
class AFlyingLifter : public AAFlyingBug {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPointLightComponent* GrabLight;
    
    UGrabberComponent* GrabberComp;
    UCapsuleComponent* GrabCapsule;
    UAudioComponent* GrabbedIdleLoop;
    UInDangerComponent* InDanger;
    UAudioComponent* ScreamComponent;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGrabSuccess OnGrabSuccess;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PreventGrabAfterSpawn;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EGrabberState GrabberState;
    float WanderingSpeed;
    float WanderingAcceleration;
    float ChaseSpeed;
    float ChaseAcceleration;
    float CarrySpeed;
    float CarryAcceleration;
    float FleeSpeed;
    float FleeAcceleration;
    float CarryCooldown;
    USoundBase* FleeSound;
    UAnimSequenceBase* FleeAnimation;
    bool ParalyzeOnGrab;
    float ExtraUpForce;
    float ScreamDistance;
    AFlyingLifter(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool SelectAnotherTarget();
    UFUNCTION(BlueprintCallable)
    void OnStateBroke(AActor* aReleasedPlayer, bool fullGrabElapsed);
    UFUNCTION()
    void OnRep_State(EGrabberState oldState);
    void OnInDanger();
    void OnActorLeftGrabZone(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
    void OnActorEnterGrabZone(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetJustGrabbed() const;
    void DropTarget();
    void ChangeState(EGrabberState aGrabberState);
};
