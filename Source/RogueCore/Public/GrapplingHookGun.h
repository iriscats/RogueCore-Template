#pragma once
#include "CoreMinimal.h"
#include "AnimatedItem.h"
#include "GraplingGunState.h"
#include "Templates/SubclassOf.h"
#include "Upgradable.h"
#include "GrapplingHookGun.generated.h"

class AGrapplingHookGun;
class UAnimMontage;
class UCoolDownItemAggregator;
UCLASS(Abstract, Blueprintable)
class AGrapplingHookGun : public AAnimatedItem, public IUpgradable {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCoolDownItemAggregator* CoolDownAggregator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDistance;
    UAnimMontage* FPReloadAnim;
    UAnimMontage* TPReloadAnim;
    UAnimMontage* FPGunslingAnim;
    UAnimMontage* TPGunslingAnim;
    float MaxSpeed;
    float MaxSpeedReleaseModifier;
    float WindUpTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool AutoFire;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    FGraplingGunState State;
    float GrapleStartTime;
    AGrapplingHookGun(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void StopGrapple();
    bool StartGrapple();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetState(const FGraplingGunState& NewState);
    UFUNCTION()
    void OnRep_State(const FGraplingGunState& prevState);
    void OnReleaseHook();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnGrappleUpdate(float DeltaSeconds);
    void OnGrappleStart();
    void OnGrappleFailed(bool TooFar);
    void OnGrappleEnd();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetWindUpProgress() const;
    static float GetCooldownDuration(TSubclassOf<AGrapplingHookGun> GrapplingHookGun);
    // Fix for true pure virtual functions not being implemented
};
