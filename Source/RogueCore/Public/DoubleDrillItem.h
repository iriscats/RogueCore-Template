#pragma once
#include "CoreMinimal.h"


#include "Engine/NetSerialization.h"
#include "DoubleDrillDamageItem.h"
#include "DualAnimatedItem.h"
#include "EDoubleDrillState.h"
#include "RejoinListener.h"
#include "Upgradable.h"
#include "UpgradableGear.h"
#include "DoubleDrillItem.generated.h"

class AActor;
class UAnimMontage;
class UDamageAsset;
class UDamageClass;
class UDamageComponent;
class UDialogDataAsset;
class UDoubleDrillAggregator;
class UFSDAudioComponent;
class UFSDPhysicalMaterial;
class UFXSystemAsset;
class UFirstPersonNiagaraComponent;
class UForceFeedbackEffect;
class UWeaponTagContainerComponent;
UCLASS(Blueprintable)
class ADoubleDrillItem : public ADualAnimatedItem, public IUpgradable, public IUpgradableGear, public IRejoinListener {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UFirstPersonNiagaraComponent* FP_Left_DrillParticlesNS;
    
    UFirstPersonNiagaraComponent* FP_Right_DrillParticlesNS;
    UDamageComponent* DamageComponent;
    UWeaponTagContainerComponent* WeaponTags;
    UFSDAudioComponent* AudioComponent;
    UDoubleDrillAggregator* Aggregator;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* FPMineMontage;
    UAnimMontage* TPMineMontage;
    UAnimMontage* FPOverheat;
    UAnimMontage* TPOverheat;
    UAnimMontage* FPGunsling;
    UAnimMontage* TPGunsling;
    UDamageAsset* Damage;
    FName MiningSpeedAudioParamterName;
    UFXSystemAsset* DrillParticles;
    UForceFeedbackEffect* DrillRumble;
    float BlockParticlesScaleFP;
    float BlockParticlesScaleTP;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    EDoubleDrillState State;
    float MovementPenalty;
    float MiningRate;
    float HeatReductionPerKill;
    FVector CarveSize;
    float CarveNoise;
    float CarverRayCastLength;
    float CarveTerrainDistanceCheck;
    float TimeToNextMine;
    float CurrentDrillSpeed;
    float DamageDistance;
    float DamageRadius;
    float FriendlyDamageRadius;
    float DamageRate;
    float armorDamageMultiplier;
    UDamageClass* DamageClass;
    float FriendlyFireModifier;
    float MaxFuel;
    float Fuel;
    float FuelUsePerDig;
    float FuelUsePerMelee;
    float SupplyStatusWeight;
    UDialogDataAsset* ShoutOutOfFuel;
    TArray<FHitResult> HitCache;
    TArray<FDoubleDrillDamageItem> DamageCache;
    float DrillParticlesDuration;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_SimulatingMining, meta=(AllowPrivateAccess=true))
    bool IsMining;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsGunslinging, meta=(AllowPrivateAccess=true))
    bool IsGunslinging;
    ADoubleDrillItem(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_StopMining();
    void Server_StartMining_Implementation();
    void Server_DoDamage_Implementation(const TArray<FDoubleDrillDamageItem>& Targets);
    void Server_DigBlock_Implementation(FVector_NetQuantize Start, FVector_NetQuantize End);
    UFUNCTION(BlueprintCallable)
    void ResupplyAmount(float amount);
    void OnTargetKilled(AActor* Target, UFSDPhysicalMaterial* PhysMat, bool wasDirectHit);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStopDrilling();
    void OnStartDrilling();
    UFUNCTION()
    void OnRep_SimulatingMining();
    UFUNCTION()
    void OnRep_IsGunslinging();
    void OnDrillParticlesTimerElapsed();
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_SetAmmoScalePercent(float Percent);
    void Client_ResupplyAmount_Implementation(float amount);
    void Client_Resupply_Implementation(float percentage);
    void BP_OnDrillDamage();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_SimulateDigDebris(FVector_NetQuantize position, int32 DebrisIndex);
    void All_SimulateDigBlock_Implementation(FVector_NetQuantize position, bool spawnParticles, int32 Material);
    void All_SimulateDamage_Implementation(const TArray<FDoubleDrillDamageItem>& Targets);
    // Fix for true pure virtual functions not being implemented
};
