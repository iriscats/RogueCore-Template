#pragma once
#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "BlitzMovementState.h"
#include "PerkInputUnlockComponent.h"
#include "BlitzUnlockComponent.generated.h"

UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBlitzUnlockComponent : public UPerkInputUnlockComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaximumMoveSpeed;
    
    float DistanceToMove;
    float StopDistance;
    float MaximumBlitzAirTime;
    FName BlitzCollisionChannel;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnReplicateMovementState, meta=(AllowPrivateAccess=true))
    FBlitzMovementState MovementState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool IsBlitzingLocally;
    FTimerHandle BlitzTimeoutHandle;
    UBlitzUnlockComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void StopBlitz();
    void StartBlitzInCameraDirection();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSetMovementState(const FBlitzMovementState& NewMovementState);
    UFUNCTION()

    void OnReplicateMovementState();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBlitzStopped();
    void OnBlitzStarted();
};
