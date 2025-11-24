#pragma once
#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "AbilityItem.h"
#include "RewindData.h"
#include "Templates/SubclassOf.h"
#include "TimeRewinder.generated.h"

class AActor;
class UAnimMontage;
class UAudioComponent;
class UCurveFloat;
class UHealthComponentBase;
class UItemCharacterAnimationSet;
class UMaterialInterface;
class UNiagaraComponent;
class UNiagaraSystem;
class USoundBase;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API ATimeRewinder : public AAbilityItem {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    FRewindData RewindData;

    FTimerHandle Handle_RewindindTimeLimit;

    FTimerHandle Handle_RewindStarted;

    FTimerHandle Handle_RewindUnEquip;

    FTimerHandle Handle_Terminating;

    FTimerHandle Handle_AlmostOverWarning;

    TSubclassOf<AActor> HologramClass;

    TWeakObjectPtr<AActor> HologramInstance;

    UItemCharacterAnimationSet* ActiveAnimationSet;

    float WarntAtTimeRemaining;

    float TimePerChargeDrain;

    float RewindDelay;

    ATimeRewinder(const FObjectInitializer& ObjectInitializer);



public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UCurveFloat* FoVModulation;
    
    USoundBase* ActivationSound;
    USoundBase* AciveSoundLoop;
    USoundBase* DeactivateSound;
    UAnimMontage* Item_SaveRewindPoint;
    UAnimMontage* Item_RewindToPoint;
    UAnimMontage* Item_Equip_Active;
    UAnimMontage* FP_Equip_Active;
    UAnimMontage* FP_RewindToPoint;
    UAnimMontage* TP_Equip_Active;
    UAnimMontage* TP_Recall;
    UMaterialInterface* PostProcessMaterial;
    UMaterialInterface* ActiveOverlayMaterial;
    UMaterialInterface* TP_ActiveOverlayMaterial;
    UNiagaraSystem* ActiveTrail;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UNiagaraComponent> ActiveTrailInstance;
    TWeakObjectPtr<UAudioComponent> LoopSoundInstance;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FRewindData RewindData;
    FTimerHandle Handle_RewindindTimeLimit;
    FTimerHandle Handle_RewindStarted;
    FTimerHandle Handle_RewindUnEquip;
    FTimerHandle Handle_Terminating;
    FTimerHandle Handle_AlmostOverWarning;
    TSubclassOf<AActor> HologramClass;
    TWeakObjectPtr<AActor> HologramInstance;
    UItemCharacterAnimationSet* ActiveAnimationSet;
    float WarntAtTimeRemaining;
    float TimePerChargeDrain;
    float RewindDelay;
    ATimeRewinder(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void Terminate();
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void Server_ShowTPRecall();
    void Server_ShowTPActivation();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SavedRewindSpot(FRewindData Data);
    void Server_RewindStarted(FRewindData Data);
    void Server_Rewind(FRewindData Data);
    void Server_DeactivateEffects();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_RewindPointPlaced();
    void Receive_Rewind();
    void Receive_AlmonstOverWarning();
    void OnDeath(UHealthComponentBase* Health);
    void InvalidatePositioningAbilities();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetTimeLimitRemainingPct() const;
    void DrainTick();
    void DeactivateAfterRewind();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowTPRecall();
    void All_ShowTPActivation();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_OnDeath();
    void All_DeactivateEffects();
};
