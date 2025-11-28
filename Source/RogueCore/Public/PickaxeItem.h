#pragma once
#include "CoreMinimal.h"

#include "Engine/NetSerialization.h"
#include "GameplayTagContainer.h"
#include "CoolDownProgressStyle.h"
#include "DelegateDelegate.h"
#include "EPickaxePartLocation.h"
#include "EPickaxeState.h"
#include "EUpdateDamageNumberColor.h"
#include "Item.h"
#include "PickaxeMeshInstance.h"
#include "PickaxePartEquip.h"
#include "StackingDamageNumberSource.h"
#include "Templates/SubclassOf.h"
#include "UpgradableGear.h"
#include "PickaxeItem.generated.h"

class UAnimMontage;
class UDamageAsset;
class UDialogDataAsset;
class UFSDPhysicalMaterial;
class UFXSystemAsset;
class UForceFeedbackEffect;
class UHealthComponentBase;
class UItemCharacterAnimationSet;
class UMaterialInterface;
class UPlayerAnimInstance;
class UPrimitiveComponent;
class USceneComponent;
class USoundCue;
class UStatusEffect;
class UWeaponTagContainerComponent;
UCLASS(Abstract, Blueprintable)
class APickaxeItem : public AItem, public IUpgradableGear, public IPickaxePartEquip, public IStackingDamageNumberSource {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool QuadDamageCarving;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnPowerAttackRecharged;
    FDelegate OnTerrainDug;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USceneComponent* FP_Root;
    USceneComponent* TP_Root;
    USceneComponent* FP_Scale;
    USceneComponent* TP_Scale;
    UPlayerAnimInstance* FPAnimInstance;
    UPlayerAnimInstance* TPAnimInstance;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* FP_EquipAnimation;
    UAnimMontage* TP_EquipAnimation;
    float EquipDuration;
    UItemCharacterAnimationSet* CharacterAnimationSet;
    UWeaponTagContainerComponent* WeaponTags;
    float SpecialCooldown;
    float SpecialCooldownRemaining;
    FCoolDownProgressStyle SpecialCooldownUI;
    int32 RockMiningBonus;
    int32 DirtMiningBonus;
    float DamageRange;
    float ExtraDamageRangeForAnimation;
    float MiningRange;
    float DamageRadius;
    TSubclassOf<UStatusEffect> OnDamageEnemySlowdownEffect;
    FGameplayTagContainer WideDamageTrackingTags;
    UDialogDataAsset* AttackExcertionShout;
    USoundCue* AttackHitSound;
    USoundCue* MiningSound;
    UForceFeedbackEffect* MineRumble;
    UForceFeedbackEffect* PartialMineRumble;
    UForceFeedbackEffect* DamageRumble;
    UDamageAsset* HitDamage;
    UDamageAsset* SpecialDamage;
    float GeneralImpactAudioVolume;
    float HitCooldown;
    float MiningDuration;
    float DistanceConsideredSameHit;
    float BlockParticlesScaleFP;
    float BlockParticlesScaleTP;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EPickaxeState State;
    USoundCue* PowerAttackRefreshedSound;
    bool PreventQMining;
    float QMiningExpectedDelay;
    float QMiningInitialDelay;
    float QMiningReducedPlayRatePct;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    double QMiningLastHitTime;
    bool CanBezerk;
    TSubclassOf<UStatusEffect> BezerkStatusEffect;
    bool PowerAttackEnabled;
    TMap<EPickaxePartLocation, FPickaxeMeshInstance> EquippedParts;
    UMaterialInterface* EquippedMaterial;
    APickaxeItem(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void SpecialTargetDamageEffects(const FVector& ImpactPoint, const FVector& ImpactNormal);
    UFUNCTION(BlueprintCallable)
    void SetSpecialCoolDownDurationRemaining(float newCooldownRemaining);
    void SetSpecialCoolDownDuration(float newCooldownDuration);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_TriggerBezerk();
    UFUNCTION(Reliable, Server)
    void Server_SetState(EPickaxeState NewState);
    UFUNCTION(Reliable, Server)
    void Server_RemoveDebrisInstance(FVector_NetQuantize HitPos, int32 DebrisIndex, int32 remappedIndex);
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void Server_HitBlock(FVector_NetQuantize position, int32 Material, bool removeDebris, bool isSpecial);
    UFUNCTION(Reliable, Server)
    void Server_DoPowerAttack();
    UFUNCTION(Reliable, Server)
    void Server_DigBlock(FVector carvePos, FVector carveDirection, int32 TerrainMaterial, bool isSpecial);
    UFUNCTION(Reliable, Server)
    void Server_DamageTarget(UPrimitiveComponent* TargetComponent, bool isSpecial, const FVector_NetQuantize& ImpactPoint, const FVector_NetQuantizeNormal& ImpactNormal, UFSDPhysicalMaterial* PhysMaterial, uint8 BoneIndex);
    void RefreshSpecialCooldown();
    void OnSpecialHitTarget(UHealthComponentBase* Health, float amount, UPrimitiveComponent* Component, UFSDPhysicalMaterial* PhysicalMaterial);
    UFUNCTION()
    void OnRep_State(EPickaxeState oldState);
    void OnLoadoutChanged();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetSpecialCooldownRemaining() const;
    float GetSpecialCooldownProgress() const;
    float GetSpecialCoolDownDuration() const;
    void DecreaseSpecialCooldownDurationRemaining_Percent(float InPercent);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_SetSpecialCoolDownDurationRemaining(float newCooldownRemaining);
    UFUNCTION(Client, Reliable)
    void Client_SetSpecialCoolDownDuration(float newCooldownDuration);
    UFUNCTION(Client, Reliable)
    void Client_EnemyKilledWithPowerAttack();
    UFUNCTION(Client, Reliable)
    void Client_DecreaseSpecialCooldownDurationRemaining_Percent(float InPercent);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_SimulateHitBlock(FVector_NetQuantize position, int32 materia, bool removeDebris, bool isSpecial);
    UFUNCTION(NetMulticast, Unreliable)
    void All_SimulateDigDebris(FVector_NetQuantize position, UFXSystemAsset* Particles, USoundCue* cue);
    UFUNCTION(NetMulticast, Unreliable)
    void All_SimulateDigBlock(FVector_NetQuantize position, bool spawnParticles, int32 Material, float Density, bool isSpecial);
    UFUNCTION(NetMulticast, Unreliable)
    void All_SimulateDamageTarget(UPrimitiveComponent* TargetComponent, bool isSpecial, const FVector_NetQuantize& ImpactPoint, const FVector_NetQuantizeNormal& ImpactNormal, UFSDPhysicalMaterial* PhysMaterial, uint8 BoneIndex);
    UFUNCTION(NetMulticast, Reliable)
    void All_DoPowerAttack();
    // Fix for true pure virtual functions not being implemented
    float GetStackingTimeLimit() const override PURE_VIRTUAL(GetStackingTimeLimit, return 0.0f;);
    int32 GetMaxCombinationsPerentry() const override PURE_VIRTUAL(GetMaxCombinationsPerentry, return 0;);
    EUpdateDamageNumberColor GetColorBehaviour() const override PURE_VIRTUAL(GetColorBehaviour, return EUpdateDamageNumberColor::ENormal;);
};
