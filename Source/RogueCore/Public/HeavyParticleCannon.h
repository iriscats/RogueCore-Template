#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AmmoDrivenWeapon.h"
#include "BoosterModuleActiveDelegate.h"
#include "DecalData.h"
#include "EUpdateDamageNumberColor.h"
#include "ReflectionTraceResult.h"
#include "StackingDamageNumberSource.h"
#include "HeavyParticleCannon.generated.h"

class AActor;
class UDamageComponent;
class UFSDPhysicalMaterial;
class UFirstPersonNiagaraComponent;
class UNiagaraComponent;
class UNiagaraSystem;
class UReflectionHitscanComponent;
class USoundBase;
class UStickyFlameSpawner;
class UTerrainType;
UCLASS(Blueprintable, NoExport)
class AHeavyParticleCannon : public AAmmoDrivenWeapon, public IStackingDamageNumberSource {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* Damage;
    
    UReflectionHitscanComponent* HitscanComponent;
    UStickyFlameSpawner* StickyFlamesSpawner;
    UFirstPersonNiagaraComponent* FirstPersonBeam;
    UFirstPersonNiagaraComponent* FirstPersonLaserSight;
    UNiagaraComponent* ThirdPersonBeam;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* BeamHitLocationGenericSound;
    USoundBase* BeamHitLocationEnemySound;
    USoundBase* BeamHitLocationEnemy_Local_Sound;
    float BeamHitSoundFadeSwitchTime;
    USoundBase* BeamHitLocationTailSound;
    USoundBase* BoosterModuleActivated;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBoosterModuleActive OnBoosterActiveChanged;
    UNiagaraSystem* ReflectedBeam;
    UNiagaraSystem* ReflectedBeam_PhotoSensitive;
    UNiagaraSystem* ReflectedLaserSight;
    UNiagaraSystem* ImpactParticle;
    UNiagaraSystem* ImpactParticle_PhotoSensitive;
    UNiagaraSystem* ProjectionModuleParticle;
    UNiagaraComponent* ImpactParticleComp;
    FDecalData ImpactDecal_ShortTime;
    FDecalData ImpactDecal_LongTime;
    bool bReloadOnButtonRelease;
    float MinTimeBetweenBiomassGain;
    bool BulkyBeam;
    float NormalBeamWidth;
    float BulkyBeamWidth;
    float ExtraRadialDamagePerSec;
    float ExtraRadialRangePerSec;
    float CancelCostPercentage;
    float ChargeupTime;
    USoundBase* StartChargeSound;
    FVector LastDecalLocation;
    bool IsNewDecalBeam;
    float ProjectionModuleDamage;
    UTerrainType* PlatformTerrainType;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_BoostActive, meta=(AllowPrivateAccess=true))
    bool BoostActive;
    bool bReloadBoostsBeam;
    float ExtraReloadTimeAfterBoost;
    float BoostExtraAmmoCost;
    float BeamDependentReloadDuration;
    FVector2D BeamDistanceRange;
    FVector2D BeamTesselationRange;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_bIsBeamActive, meta=(AllowPrivateAccess=true))
    bool bIsBeamActive;
    AHeavyParticleCannon(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateBeamsVisibility(bool isBeamVisible);
    UFUNCTION(BlueprintCallable)
    void UpdateBeam(const FReflectionTraceResult& Path);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSetBoostActive(bool NewActive);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetBeamActive(bool inIsBeamActive);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Server_ExplodePlatform(FVector Location);
    void OnTargetKilled(AActor* Target, UFSDPhysicalMaterial* PhysMat, bool wasDirectHit);
    UFUNCTION()
    void OnRep_BoostActive();
    UFUNCTION()
    void OnRep_bIsBeamActive();
    void IsHittngEnemyChanged(bool isHittingEnemy);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_AddAmmoOnKill();
    void ChargeUpComplete();
    void ChargeChanged(bool isCharging);
    // Fix for true pure virtual functions not being implemented
    float GetStackingTimeLimit() const override PURE_VIRTUAL(GetStackingTimeLimit, return 0.0f;);
    int32 GetMaxCombinationsPerentry() const override PURE_VIRTUAL(GetMaxCombinationsPerentry, return 0;);
    EUpdateDamageNumberColor GetColorBehaviour() const override PURE_VIRTUAL(GetColorBehaviour, return EUpdateDamageNumberColor::ENormal;);
};
