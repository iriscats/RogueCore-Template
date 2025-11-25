#pragma once
#include "CoreMinimal.h"
#include "AudioWithCooldown.h"
#include "DamageData.h"
#include "DelegateDelegate.h"
#include "FullHealthSignatureDelegate.h"
#include "HealthChangedSigDelegate.h"
#include "HealthComponent.h"
#include "HealthRegeneratingChangedDelegate.h"
#include "HealthRegenerationParams.h"
#include "OnPlayerShieldDestroyedDelegate.h"
#include "PlayerHitSigDelegate.h"
#include "RejoinListener.h"
#include "Templates/SubclassOf.h"
#include "PlayerHealthComponent.generated.h"

class AActor;
class AController;
class APlayerCharacter;
class UCurveFloat;
class UDamageClass;
class UDamageTag;
class UDialogDataAsset;
class UFXSystemAsset;
class UFXSystemComponent;
class UPlayerDamageTakenMutator;
class UStatusEffect;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UPlayerHealthComponent : public UHealthComponent, public IRejoinListener {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHealthChangedSig OnMaxHealthChanged;
    
    FHealthChangedSig OnTargetArmorChanged;
    FFullHealthSignature OnFullHealthCannotHeal;
    FFullHealthSignature OnHealedFromCrystalEvent;
    FHealthRegeneratingChanged OnHealthRegeneratingChanged;
    UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlayerShieldDestroyed OnPlayerShieldDestroyed;
    FPlayerHitSig OnPlayerHit;
    FDelegate OnIronWillActivated;
    FDelegate OnArmorUpgraded;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDamageClass* FallingDamageClass;
    UDialogDataAsset* OnHealedShout;
    UCurveFloat* ArmorRegenCurve;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerCharacter* Character;
    UFXSystemAsset* GenericImpactParticles;
    UFXSystemAsset* ShieldLinkEffect;
    UPlayerDamageTakenMutator* DamageTakenMutator;
    UStatusEffect* IronWillStatusEffect;
    TSubclassOf<UStatusEffect> DodgeStatusEffectClass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFXSystemComponent* ShieldLinkInstance;
    TSubclassOf<UStatusEffect> IronWillStatusEffectClass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_MaxHealth, meta=(AllowPrivateAccess=true))
    float MaxHealth;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_MaxArmor, meta=(AllowPrivateAccess=true))
    float MaxArmor;
    float ArmorDamageReduction;
    float ArmorDegradationRate;
    float TemporaryHealthDecayRate;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_TemporaryHealth, meta=(AllowPrivateAccess=true))
    float TemporaryHealth;
    float MaxTemporaryHealth;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ArmorDamage, meta=(AllowPrivateAccess=true))
    float ArmorDamage;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_TargetArmorDamage, meta=(AllowPrivateAccess=true))
    float TargetArmorDamage;
    float IronWillTimeToActivate;
    float MaxArmorBase;
    float ReviveHealthReturnRatio;
    float ReviveArmorReturnRatio;
    float HealthPerCrystalVolume;
    float ShieldRegenDelay;
    float InvulnerabilityDuration;
    float ReviveInvulnerabilityTime;
    float HealthRegenTarget;
    FHealthRegenerationParams HealthRegeneration;
    FAudioWithCooldown AudioFriendlyFire;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool IronWillActive;
    UPlayerHealthComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UpgradeShield(float CapacityAmount, float RegenAmount, float DegradationRate);
    float TakeDamageWithoutDelegates(float damageAmount, const FDamageData& DamageData, const TArray<UDamageTag*>& Tags, bool ignoreModifiers);
    void SetMaxShield(float max);
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    UStatusEffect* SetIronWillStatusEffect(TSubclassOf<UStatusEffect> steClass);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_TryActivateIronWill();
    UFUNCTION(BlueprintAuthorityOnly, Server, Reliable)
    void Server_HealArmor(float amount);
    void ResetTimeSinceLastDamage();
    void RemoveShieldUpgrade(float CapacityAmount, float RegenAmount, float DegradationRate);
    UFUNCTION()
    void OnRep_TemporaryHealth(float oldTempHealth);
    UFUNCTION()
    void OnRep_TargetArmorDamage(float oldDamage);
    UFUNCTION()
    void OnRep_MaxHealth();
    UFUNCTION()
    void OnRep_MaxArmor();
    UFUNCTION()
    void OnRep_ArmorDamage(float oldDamage);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLowHealth() const;
    bool IsLocallyControlled() const;
    float HealWithoutShout(float amount);
    static float GetTargetArmorPctFromValues(float max, float Target);
    float GetShieldRegenFactor() const;
    float GetRemainingIronWillActivationTime() const;
    float GetMaxArmorUpgrades() const;
    bool GetIsHealthRegenerating() const;
    bool GetIronWillActive() const;
    float GetHealthRegeneratingTargetRatio() const;
    float GetBaseMaxHealth() const;
    void DamageArmor(float amount);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_SetHealthRegenerating(bool isRegenerating);
    UFUNCTION(BlueprintCallable, Client, Unreliable)
    void Client_OnFriendlyFire(AController* EventInstigator, AActor* DamageCauser);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_HealthFullCannotHeal();
    UFUNCTION(BlueprintCallable, Client, Unreliable)
    void Client_ArmorDamaged(float amount);
    UFUNCTION(BlueprintAuthorityOnly, Server, Reliable)
    void Cheat_Revive();
    UFUNCTION(BlueprintAuthorityOnly, Server, Reliable)
    void Cheat_KillPlayer();
    bool CanActivateIronWill() const;
    // Fix for true pure virtual functions not being implemented
};
