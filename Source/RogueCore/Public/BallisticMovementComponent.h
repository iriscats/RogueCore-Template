#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Components/ActorComponent.h"
#include "LaunchDelegateDelegate.h"
#include "BallisticMovementComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UBallisticMovementComponent : public UActorComponent {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLaunchDelegate OnLaunch;
    
    FLaunchDelegate OnLanding;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GravityMultiplier;
    float LaunchAngleOffset;
    float MinMoveDistance;
    float SampleZOffset;
    float RotateDelay;
    float LaunchDelay;
    float LandingDelay;
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_bIsMoveActive, meta=(AllowPrivateAccess=true))
    bool bIsMoveActive;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_LaunchVelocity, meta=(AllowPrivateAccess=true))
    FVector LaunchVelocity;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FRotator TargetRotation;
    float AnticipatedTotalAirborneTime;
    float Pitch;
    UBallisticMovementComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void StartMovement(FVector InLaunchVelocity, FRotator InTargetRotator, float InFlightTime);
    UFUNCTION(BlueprintCallable)
    void OnRep_LaunchVelocity();
    UFUNCTION()
    void OnRep_bIsMoveActive();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsMoveActive() const;
    bool IsAnimating() const;
};
