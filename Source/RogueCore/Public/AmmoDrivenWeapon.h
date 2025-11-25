#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Curves/CurveFloat.h"
#include "AmmoDrivenGenericEventDelegate.h"
#include "AmmoValue.h"
#include "AmountChangedSignatureDelegate.h"
#include "AnimatedItem.h"
#include "DelegateDelegate.h"
#include "EAmmoWeaponState.h"
#include "ItemAnimationItem.h"
#include "RecoilSettings.h"
#include "ResupplliedSignatureDelegate.h"
#include "TracerData.h"
#include "Upgradable.h"
#include "UpgradableGear.h"
#include "WeaponFireOwner.h"
#include "AmmoDrivenWeapon.generated.h"

class APlayerCharacter;
class UAmmoDriveWeaponAggregator;
class UAnimMontage;
class UAudioComponent;
class UCurveFloat;
class UDialogDataAsset;
class UFXSystemAsset;
class UForceFeedbackEffect;
class UItemUpgrade;
class ULightComponent;
class UNiagaraSystem;
class USoundBase;
class USoundCue;
class UWeaponFireComponent;
class UWeaponTagContainerComponent;
UCLASS(Abstract, Blueprintable)
class AAmmoDrivenWeapon : public AAnimatedItem, public IWeaponFireOwner, public IUpgradable, public IUpgradableGear {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWeaponTagContainerComponent* WeaponTags;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAmountChangedSignature OnClipCountChanged;
    FResupplliedSignature OnAmmoResupplied;
    FDelegate OnTryReloadEvent;
    FDelegate OnReloadingEvent;
    FDelegate OnShotFiredEvent;
    FAmmoDrivenGenericEvent OnStoppedUsingEvent;
    FDelegate OnAmmoUpdatedLocal;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool LoopFireAnimation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    UAnimMontage* FP_ReloadAnimation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    ULightComponent* MuzzleFlashLight;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAudioComponent> FireSoundInstance;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ReserveCount, meta=(AllowPrivateAccess=true))
    FAmmoValue ReserveCount;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ClipCount, meta=(AllowPrivateAccess=true))
    FAmmoValue ClipCount;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float AutoReloadDuration;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsFiring, meta=(AllowPrivateAccess=true))
    bool IsFiring;
 
    UWeaponFireComponent* WeaponFire;
    UAmmoDriveWeaponAggregator* Aggregator;
    bool OverHeatOnNoAmmo;
    float LoopFireAnimationBlendoutTime;
    UAnimMontage* FP_FireAnimation;
    UAnimMontage* TP_FireAnimation;
    UAnimMontage* FP_ReloadAnimation_Empty;
    FItemAnimationItem OverheatAnimation;
    TArray<FItemAnimationItem> GunslingAnimations;
    UAnimMontage* TP_ReloadAnimation;
    UAnimMontage* TP_ReloadAnimation_Empty;
    UAnimMontage* WPN_Fire;
    UAnimMontage* WPN_FireLastBullet;
    UAnimMontage* WPN_Reload;
    UAnimMontage* WPN_ReloadEmpty;
    UAnimMontage* WPN_Reload_TP;
    UNiagaraSystem* MuzzleParticles;
    UNiagaraSystem* TPMuzzleParticles;
    bool UseTriggeredMuzzleParticles;
    FTracerData Tracer;
    UFXSystemAsset* CasingParticles;
    bool UseTriggeredCasingParticleSystem;
    FRuntimeFloatCurve MuzzleFlashLightCurve;
    USoundBase* FireSound;
    USoundCue* RicochetSound;
    UFXSystemAsset* RicochetParticle;
    float FireSoundDelayToTail;
    USoundBase* FireSoundTail;
    bool IsFireSoundTail2D;
    UForceFeedbackEffect* FireForceFeedbackEffect;
    float FireSoundFadeDuration;
    USoundCue* ReloadSound;
    int32 BulletsRemainingForNearEmptySound;
    UCurveFloat* BulletsRemainingNearEmptyVolumeCurve;
    bool PlayNearEmptySoundsIn3D;
    bool PlayClipReachesZeroSoundsIn3D;
    bool PlayEmptySoundsIn3D;
    USoundBase* NearEmptySound;
    USoundBase* ClipReachesZeroSound;
    USoundBase* DryFireSound;
    UDialogDataAsset* ShoutShotFired;
    UDialogDataAsset* ShoutOutOfAmmo;
    UDialogDataAsset* ShoutReloading;
    int32 MaxAmmo;
    int32 ClipSize;
    int32 ShotCost;
    float RateOfFire;
    int32 BurstCount;
    float BurstCycleTime;
    float ReloadDuration;
    bool ShouldInitAmmoAtBeginPlay;
    int32 ManualHeatReductionAmmo;
    float FireInputBufferTime;
    USoundCue* AutoReloadCompleteCue;
    FAmmoDrivenGenericEvent OnItemAutoReloaded;
    float SupplyStatusWeight;
    float CycleTimeLeft;
    bool UseCustomReloadDelay;
    float CustomReloadDelay;
    float ReloadTimeLeft;
    bool AutomaticReload;
    bool CanReload;
    float HoldToFirePercentOfFireRatePenalty;
    FRecoilSettings RecoilSettings;
    bool ApplyRecoilAtEndOfBurst;
    float EndOfBurstRecoilMultiplier;
    bool HasAutomaticFire;
    bool OverheatOnReload;
    bool ManualHeatReductionOnReload;
    int32 MaxManualHeatReductionCharges;
    float ManualHeatReductionValue;
    bool CanManuallyReload;
    EAmmoWeaponState WeaponState;
    bool HasRejoinedInitialized;
    AAmmoDrivenWeapon(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Upgraded_Blueprint_Implementation(const TArray<UItemUpgrade*>& upgrades);
    UFUNCTION(BlueprintCallable)
    void UpdateHoldToFire();
    void TransferAmmoToClip(int32 amount);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_UpdateClipCount(const FAmmoValue& Val);
    UFUNCTION()
    void Server_UpdateClipCount_Implementation(const FAmmoValue& Val);
    void Server_UpdateAmmoCount(const FAmmoValue& Val);
    UFUNCTION()
    void Server_UpdateAmmoCount_Implementation(const FAmmoValue& Val);
    void Server_StopReload(float blendOutTime);
    UFUNCTION()
    void Server_StopReload_Implementation(float blendOutTime);
    void Server_ReloadWeapon(bool isFullyEmpty);
    UFUNCTION()
    void Server_ReloadWeapon_Implementation(bool isFullyEmpty);
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void Server_PlayWeaponEmptySound_3D();
    UFUNCTION()
    void Server_PlayWeaponEmptySound_3D_Implementation();
    void Server_PlayBurstFire(uint8 shotCount);
    UFUNCTION()
    void Server_PlayBurstFire_Implementation(uint8 shotCount);
    void Server_Gunsling(uint8 Index);
    UFUNCTION()
    void Server_Gunsling_Implementation(uint8 Index);
    void ResupplyToPercent(float percentage);
    void ResupplyAmmo(int32 amount);
    void RecieveFiredWeapon();
    void Receive_ReloadEnd();
    void Receive_ReloadBegin();
    void Receive_IsFiringChanged(bool NewValue);
    void OnWeaponFireEnded();
    void OnWeaponFired(const FVector& Location);
    void OnTagBonusChanged();
    void OnRicochet(const FVector& Origin, const FVector& Location, const FVector& Normal);
    UFUNCTION()
    void OnRep_ReserveCount();
    UFUNCTION()
    void OnRep_IsFiring();
    UFUNCTION()
    void OnRep_ClipCount();
    void MoveAmmoFromReserve(int32 amount);
    void MoveAmmoBackToReserve(int32 amount);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsClipFull() const;
    void InstantlyReload();
    void InitAmmo();
    void CustomEvent1(const UItemUpgrade* Event);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_SetAmmoScalePercent(float Percent);
    UFUNCTION()
    void Client_SetAmmoScalePercent_Implementation(float Percent);
    void Client_SetAmmo(float percentage);
    UFUNCTION()
    void Client_SetAmmo_Implementation(float percentage);
    void Client_ResupplyAmmo(int32 count);
    UFUNCTION()
    void Client_ResupplyAmmo_Implementation(int32 count);
    void Client_RefillAmmo(float percentage);
    UFUNCTION()
    void Client_RefillAmmo_Implementation(float percentage);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_StopReload(float blendOutTime);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_StartReload(bool isFullyEmpty);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_PlayWeaponEmptySound_3D();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_PlayBurstFire(uint8 shotCount);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_Gunsling(uint8 Index);
    // IWeaponFireOwner implementation
    APlayerCharacter* GetPlayerCharacter() const override PURE_VIRTUAL(GetPlayerCharacter, return NULL;);
    FQuat GetMuzzleQuat() const override PURE_VIRTUAL(GetMuzzleQuat, return FQuat{};);
    FVector GetMuzzleLocation() const override PURE_VIRTUAL(GetMuzzleLocation, return FVector{};);
    bool GetIsLocallyControlled() const override PURE_VIRTUAL(GetIsLocallyControlled, return false;);
    bool GetIsFirstPerson() const override PURE_VIRTUAL(GetIsFirstPerson, return false;);
};
