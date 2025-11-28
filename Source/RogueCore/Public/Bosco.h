#pragma once
#include "CoreMinimal.h"

#include "Engine/NetSerialization.h"
#include "GameplayTagContainer.h"
#include "BXEUnlockInstance.h"
#include "BoscoLightSetting.h"
#include "BoscoUnlockRecordEntry.h"
#include "DamageData.h"
#include "DeepPathfinderCharacter.h"
#include "EAbilityIndex.h"
#include "EDroneAIState.h"
#include "ItemIDInterface.h"
#include "Minion.h"
#include "NotifyMessageReceiver.h"
#include "ReviveUsedSigDelegate.h"
#include "SaveGameIDInterface.h"
#include "Skinnable.h"
#include "StateChangedSigDelegate.h"
#include "Upgradable.h"
#include "UpgradableGear.h"
#include "WeaponFireOwner.h"
#include "Bosco.generated.h"

class AActor;
class ABoscoController;
class APlayerCharacter;
class UAnimMontage;
class UAnimSequenceBase;
class UAudioComponent;
class UBobbingComponent;
class UBoscoAbillity;
class UBoscoAbillityComponent;
class UBoscoProjectileAbillity;
class UDialogDataAsset;
class UDroneMiningToolBase;
class UDroneSkinnableComponent;
class UFXSystemAsset;
class UHealthComponent;
class UHitscanComponent;
class UItemID;
class UItemUpgrade;
class UNiagaraComponent;
class UPointLightComponent;
class USkeletalMeshComponent;
class USoundBase;
class USoundCue;
class USpotLightComponent;
class UTerrainMaterial;
class UUpgradableBoscoComponent;
UCLASS(Blueprintable)
class ROGUECORE_API ABosco : public ADeepPathfinderCharacter, public IWeaponFireOwner, public IUpgradableGear, public IUpgradable, public ISaveGameIDInterface, public ISkinnable, public IItemIDInterface, public INotifyMessageReceiver, public IMinion {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHealthComponent* HealthComponent;
    
    UBoscoAbillityComponent* PrimaryAbility;
    UBoscoAbillityComponent* SecondaryAbility;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    TArray<UBoscoAbillityComponent*> Abilities;
    UDroneMiningToolBase* MiningTool;
    UBobbingComponent* BobbingComponent;
    USkeletalMeshComponent* BoscoMesh;
    UHitscanComponent* DroneHitScan;
    USpotLightComponent* SpotLightComponent;
    UPointLightComponent* PointLightComponent;
    UNiagaraComponent* LTrailNS;
    UNiagaraComponent* RTrailNS;
    UAudioComponent* MomentumSound;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDialogDataAsset* DefendDrilldozerShout;
    UDialogDataAsset* DefendGenericShout;
    UDialogDataAsset* MineOrderShout;
    UDialogDataAsset* KillOrderShout;
    UDialogDataAsset* GoToOrderShout;
    UDialogDataAsset* ReviveOrderShout;
    UDialogDataAsset* PickupGemShout;
    UDialogDataAsset* ReviveThankShout;
    UDialogDataAsset* GeneralCallShout;
    UDialogDataAsset* VacuumShout;
    USoundBase* MineResponse;
    USoundBase* CombatResponse;
    USoundBase* LightResponse;
    USoundBase* ReviveResponse;
    USoundBase* AbillityResponse;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundBase* CurrentResponse;
    float ResponseTime;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FReviveUsedSig OnReviveused;
    bool ShouldSelfDestructOnMultiplePlayers;
    FStateChangedSig OnStateChanged;
    TArray<FBoscoUnlockRecordEntry> Unlocks;
 
    FGameplayTagContainer LosMatchTags;
    float SeeTargetTime;
    USoundBase* AbillityErrorSound;
    float IncreasedMiningArea;
    float MiningAnimationRate;
    float TimeToResetMiningBoost;
    float MiningBoosMultiplier;
    TArray<UItemUpgrade*> upgrades;
    UBoscoProjectileAbillity* RocketAbillity;
    UBoscoProjectileAbillity* CryoGrenadeAbillity;
    FGuid SavegameID;
    UItemID* ItemID;
    UUpgradableBoscoComponent* Upgradable;
    UAnimMontage* SaluteAnimation;
    UAnimSequenceBase* PickupGemAnimation;
    UAnimSequenceBase* DropGemAnimation;
    TArray<UAnimSequenceBase*> HitReaction;
    float SaluteDuration;
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDroneSkinnableComponent* Skinnable;
    TArray<FBoscoLightSetting> LightSettings;
    int32 TargetLightSetting;
    TArray<UBoscoAbillity*> CombatAbillities;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    AActor* RotateTarget;
    FVector LookAtLocation;
    USoundCue* ShootSound;
    float ShootSoundFadeout;
    USoundCue* ShootSoundTail;
    UAudioComponent* ShootSoundInstance;
    UFXSystemAsset* MuzzleEffect;
    UFXSystemAsset* TracerEffect;
    float FireRate;
    int32 MinShotsInBurst;
    int32 MaxShotsInBurst;
    float MaxRandomBurstCooldown;
    float MinRandomBurstCooldown;
    float MaxFiringAngle;
    float MaxEngagementRange;
    float MinTracerDistance;
    float TracerSpeed;
    USoundBase* ReviveSirens;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAudioComponent> ReviveSirensComponent;
    float DistanceToFacePlayer;
    float RotationSpeed;
    float PrepareToMineRange;
    float MiningRange;
    int32 MaxRevives;
    bool IsFiring;
    bool IsInRangeToMine;
    bool IsPreparedToMine;
    bool IsMining;
    bool IsReviving;
    bool IsRotateMode;
    ABoscoController* DroneController;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    EDroneAIState CurrentState;
    ABosco(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UsePlayerActivatedAbillity(EAbilityIndex Index, AActor* aTarget, const FVector& aLocation);
    void UseABillity();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void StopShootingSound();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StateChanged(EDroneAIState aCurrentState);
    void StartSelfDestruct();
    void SetIsReviving(bool aIsReviving);
    void SetIsRepairing(bool isRepairing);
    void SelfDestruct();
    void ReviveCounterChanged(int32 remainingCharges);
    void Respond();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void PlaySalute();
    void OnWeaponFired(const FVector& Location);
    void OnTargetBurrowChange(bool burrowed);
    UFUNCTION()
    void OnRep_State(EDroneAIState prevState);
    void OnReadyToShoot();
    void OnNotReadyToShoot();
    void OnHit(float amount, float BaseAmount, const FDamageData& DamageData);
    void OnGrabbedGem();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void MineEffects(UTerrainMaterial* aTerrainMaterial, FVector_NetQuantize aLocation, FRotator aRotation);
    UUpgradableBoscoComponent* GetUpgradeComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FBXEUnlockInstance> GetUnlocks() const;
    int32 GetReviveCharges() const;
    UBoscoAbillityComponent* GetPlayerAbillity() const;
    EDroneAIState GetCurrentState() const;
    bool GetCarryInterrupted() const;
    bool DoPickupGemAnimation();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_OnSelfDestruct();
    void AddReviveCharges(int32 charges);
    // Fix for true pure virtual functions not being implemented
    APlayerCharacter* GetPlayerCharacter() const override PURE_VIRTUAL(GetPlayerCharacter, return NULL;);
    FQuat GetMuzzleQuat() const override PURE_VIRTUAL(GetMuzzleQuat, return FQuat{};);
    FVector GetMuzzleLocation() const override PURE_VIRTUAL(GetMuzzleLocation, return FVector{};);
    bool GetIsLocallyControlled() const override PURE_VIRTUAL(GetIsLocallyControlled, return false;);
    bool GetIsFirstPerson() const override PURE_VIRTUAL(GetIsFirstPerson, return false;);
};
