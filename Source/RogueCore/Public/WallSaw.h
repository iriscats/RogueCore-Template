#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "FakeSawMover.h"
#include "SawFakeMoveState.h"
#include "WallSaw.generated.h"

class UCapsuleComponent;
class UCurveFloat;
class UFXSystemComponent;
class UPrimitiveComponent;
UCLASS(Blueprintable)
class AWallSaw : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UCapsuleComponent* HitCapsule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpeedCof;
    UCurveFloat* VelOverTime;
    UFXSystemComponent* GroundParticles;
    FFakeSawMover FakeMover;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_PosVel, meta=(AllowPrivateAccess=true))
    FSawFakeMoveState PosVel;
    float PopWeakpointRadius;
    float PlayerHitRangeFromCenter;
    AWallSaw(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UpdateCheckForWeakpoints();
    void SetMovementDirection(FVector Direction);
    void PushEnemyAndCheckForWeakpoint(AActor* Actor);
    UFUNCTION()
    void OnRep_PosVel(const FSawFakeMoveState& NewPosVel);
    void OnDurationEnd();
    void Initialize(FVector Direction);
    bool HasJustHit(AActor* Enemy);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void GrazeOverlapCallback(AActor* Actor, UPrimitiveComponent* prim);
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_Initialize(const FTransform& Transform, const FVector& Direction);
};
