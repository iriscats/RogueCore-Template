#pragma once
#include "CoreMinimal.h"
#include "DamageData.h"
#include "EInputKeys.h"
#include "ERockCrackerstate.h"
#include "RessuplyPod.h"
#include "RockCrackerStateDelegateDelegate.h"
#include "RockCrackerPod.generated.h"

class APlayerCharacter;
class ARockCrackerPod;
class UContinuousUsableComponent;
class UDialogDataAsset;
class UFriendlyHealthComponent;
class UHealthComponentBase;
UCLASS(Blueprintable, NoExport)
class ARockCrackerPod : public ARessuplyPod {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFriendlyHealthComponent* Health;
    
    UContinuousUsableComponent* RepairUsable;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRockCrackerStateDelegate OnRockCrackerStateChanged;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DrainPerSecond;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_PodState, meta=(AllowPrivateAccess=true))
    ERockCrackerstate PodState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ARockCrackerPod* EndPointDrill;
    UDialogDataAsset* InDangerDialogue;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_LightsAreGreen, meta=(AllowPrivateAccess=true))
    bool LightsAreGreen;
    float DrainImmunityTime;
    float YellowLightsThreshold;
    float HealPerTick;
    ARockCrackerPod(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SwitchYellowLights(bool isGreen);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetPodState(ERockCrackerstate NewPodState);
    UFUNCTION(BlueprintCallable)
    void OnRepairTick(APlayerCharacter* User, EInputKeys Key);
    UFUNCTION()
    void OnRep_PodState(ERockCrackerstate oldState);
    UFUNCTION()
    void OnRep_LightsAreGreen();
    void OnPodDamaged(float damageInfliced, const FDamageData& DamageData, bool anyHealthLost, UHealthComponentBase* HealthComponent);
    void OnExitState(ERockCrackerstate NewPodState);
    void OnEventStarted();
    void OnEventEnded(bool wasSuccess);
    void OnEnterState(ERockCrackerstate NewPodState);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsBroken() const;
    ERockCrackerstate GetPodState() const;
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_SwitchYellowLights(bool isGreen);
};
