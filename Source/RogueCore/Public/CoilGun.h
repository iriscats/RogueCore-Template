#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Curves/CurveFloat.h"
#include "Engine/NetSerialization.h"
#include "BulletPathSegment.h"
#include "ChargedWeapon.h"
#include "CoilMaterial.h"
#include "ContrailSettings.h"
#include "EUpdateDamageNumberColor.h"
#include "ShotMultiplier.h"
#include "StackingDamageNumberSource.h"
#include "Templates/SubclassOf.h"
#include "CoilGun.generated.h"

class AActor;
class ACoilgunWeaponTrail;
class UCoilgunTrailSpawner;
class UDamageComponent;
class UFSDPhysicalMaterial;
class UHealthComponentBase;
class UNiagaraComponent;
class UNiagaraSystem;
class UPrimitiveComponent;
class UStaticMesh;
class UStatusEffect;
UCLASS(Blueprintable)
class ROGUECORE_API ACoilGun : public AChargedWeapon, public IStackingDamageNumberSource {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* DamageComponent;
    
    UDamageComponent* OverchargeDamageComponent;
    UDamageComponent* WeaponBlastDamage;
    UDamageComponent* ShotwaveBonusDamage;
    UDamageComponent* MoleBonusDamage;
    UNiagaraComponent* FullyChargedParticles;
    UNiagaraComponent* FP_OverchargeIndicatorParticles;
    UNiagaraComponent* TP_FullyChargedParticles;
    UCoilgunTrailSpawner* TrailSpawner;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FContrailSettings TrailSettings;
    UStaticMesh* ImpactMeshCarver;
    UNiagaraSystem* N_ImpactParticles;
    TSubclassOf<UStatusEffect> ChargeResistanceStatusEffect;
    TSubclassOf<UStatusEffect> ChargeWeaknessStatusEffect;
    TArray<TSubclassOf<ACoilgunWeaponTrail>> TrailClasses;
    UNiagaraSystem* CustomMuzzleFlash;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<AActor*> HitActorCache;
    FName CoilParamName;
    TArray<FCoilMaterial> DynamicCoilMaterials;
    FRuntimeFloatCurve CoilColorCurve;
    TArray<UStatusEffect*> RecordedAilments;
    float MaxAfflictionTime;
    float ShotWidth;
    float BonusShotWidth;
    float ImpactFearFactor;
    float OverChargedShotMaxPower;
    float MaxOverchargeTime;
    float OverchargeTimeStep;
    float BrokenShieldboostDuration;
    float MinUndercharge;
    float TriBustCancelTime;
    float TriBurstShotPowerMultiplier;
    float TriBurstAmmoMultiplier;
    float TriBurstShotCarvingMultiplier;
    int32 FirstDynamicIndex;
    int32 LastDynamicIndex;
    ACoilGun(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void UpdateAfflictions();
    void SetDynamicMaterials();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ToggleCharingBonuses(bool Enabled);
    void Server_SpawnTrail_Implementation(const FVector_NetQuantize& Location, const FRotator& Rotation, float HalfHeight, bool fireTrailEnabled);
    void Server_SpawnGroundTrail_Implementation(const FVector_NetQuantize& Location, const FVector& Direction, float chargeMultiplier);
    void Server_SetShotPower_Implementation(const float& Power);
    void Server_RegisterPrimaryHit_Implementation(UPrimitiveComponent* Target, UFSDPhysicalMaterial* PhysMaterial, const FVector_NetQuantize& Origin, const FVector_NetQuantize& Location, int32 BoneIndex, FShotMultiplier Multiplier, int32 mole);
    void Server_RegisterBonusHit_Implementation(AActor* Target);
    void Server_RegisterBlastHit_Implementation(AActor* Target, const FVector_NetQuantize& Location, UPrimitiveComponent* comp);
    void Server_HitTerrain_Implementation(const FVector_NetQuantize& Location, const FVector_NetQuantize& End, float maxCarveDepth);
    void Server_FearTarget_Implementation(AActor* Target);
    void Server_ClearAilments_Implementation();
    void OnTriBurstCancled();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnShieldBrokenBoost();
    void OnShieldBrokeBoostStopped();
    void OnShieldBoostEnded();
    void OnFireKill(AActor* Target);
    void OnEnemyKilled(AActor* Target, UFSDPhysicalMaterial* PhysicalMaterial, bool wasDirectHit);
    void OnDamageTarget(UHealthComponentBase* Health, float amount, UPrimitiveComponent* Component, UFSDPhysicalMaterial* PhysicalMaterial);
    void OnCharacterShieldBroke(AActor* brokeChar);
    void OnBulletPathComplete(const TArray<FBulletPathSegment>& Path);
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_ShowHit(const FVector_NetQuantize& Location, const FVector_NetQuantize& Rotation);
    void All_ShieldBroken_Implementation();
    void All_AdjustTrail_Implementation(ACoilgunWeaponTrail* Trail, float Length);
    // StackingDamageNumberSource interface implementation
    virtual float GetStackingTimeLimit() const override { return 0.0f; }
    virtual int32 GetMaxCombinationsPerentry() const override { return 0; }
    virtual EUpdateDamageNumberColor GetColorBehaviour() const override { return EUpdateDamageNumberColor::ENormal; }
};
