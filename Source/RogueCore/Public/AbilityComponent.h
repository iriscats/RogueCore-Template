#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DelegateDelegate.h"
#include "EAbilityActivationType.h"
#include "EAbilityBlockedOn.h"
#include "EAbilityDeactivationType.h"
#include "FloatDelegateDelegate.h"
#include "IntDelegateDelegate.h"
#include "AbilityComponent.generated.h"

class APlayerCharacter;
class UAbilityData;
class UDialogDataAsset;
UCLASS(Abstract, Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UAbilityComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))

    bool AnyTeamAbilityActive;

    bool AnyAbilityOfThisTypeActive;

    bool CanActivateWhenDead;

    UAbilityComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;



public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatDelegate OnAbilityActivated;
    
    FDelegate OnAbilityDeactivated;
    FFloatDelegate CooldownStarted;
    FFloatDelegate OnCooldownUpdated;
    FIntDelegate OnChargesChanged;
    FIntDelegate OnMaxChargesChanged;
    FDelegate OnChargeConsumed;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAbilityData* AbilityData;
    float CoolDownTime;
    float EffectTime;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CooldownTimer;
    float EffectTimer;
    float RangeMultiplier;
    int32 UseCost;
    int32 charges;
    int32 MaxCharges;
    EAbilityBlockedOn AbilityBlockedOn;
    EAbilityActivationType ActivationType;
    EAbilityDeactivationType DeactivationType;
    UDialogDataAsset* FullyChargedShout;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsEffectActive, meta=(AllowPrivateAccess=true))
    bool IsEffectActive;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool AnyTeamAbilityActive;
    bool AnyAbilityOfThisTypeActive;
    bool CanActivateWhenDead;
    UAbilityComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetRegenBlocked(bool IsBlocked);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_DeactivateAbility();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ActivateAbility();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_EffectTimerFinishedAll();
    void Receive_EffectTimerFinished();
    void Receive_ActivatedAbilityServer();
    void Receive_ActivatedAbilityLocal();
    void Receive_ActivatedAbilityAll();
    void QueueDeactivation();
    UFUNCTION()
    void OnRep_IsEffectActive();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasTotalChargePct(float pct) const;
    int32 GetMaxCharges() const;
    bool GetIsEffectActive() const;
    int32 GetCharges() const;
    APlayerCharacter* GetCharacter() const;
    UAbilityData* GetAbilityData() const;
    void DecreaseCurrentCooldownBySeconds(const float InSeconds);
    void DecreaseCurrentCooldownByPercent(const float InPercent);
    void DeactivateAbility();
    void ConsumeCharge(int32 amount);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_DecreaseCurrentCooldownBySeconds(const float InSeconds);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_DecreaseCurrentCooldownByPercent(const float InPercent);
    void ActivateAbility(bool ReleaseToDeactivate);
};
