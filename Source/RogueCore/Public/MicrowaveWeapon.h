#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/NetSerialization.h"
#include "AmmoDrivenWeapon.h"
#include "LensActivedDelegateDelegate.h"
#include "LensDeactivedDelegateDelegate.h"
#include "MicrowaveLense.h"
#include "MultiHitScanHits.h"
#include "MultiHitscanHit.h"
#include "Templates/SubclassOf.h"
#include "MicrowaveWeapon.generated.h"

class AActor;
class ABoil;
class UCapsuleHitscanComponent;
class UDamageComponent;
class UElementComponent;
class UFSDPhysicalMaterial;
class UFXSystemAsset;
class UFirstPersonNiagaraComponent;
class UHealthComponentBase;
class UNiagaraComponent;
class UNiagaraSystem;
class UPrimitiveComponent;
class USoundCue;
class UStatusEffect;
UCLASS(Blueprintable, NoExport)
class ROGUECORE_API AMicrowaveWeapon : public AAmmoDrivenWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* DamageComp;
    
    UCapsuleHitscanComponent* CapsuleHitscanComp;
    UFirstPersonNiagaraComponent* FP_MuzzleParticle;
    UNiagaraComponent* TP_MuzzleParticle;
    UDamageComponent* ExplodingTargetsDamageComponent;
    UDamageComponent* RadiantSuperheaterHeat;
    UDamageComponent* RadiantSuperheaterFrostShock;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLensActivedDelegate OnLenseActivated;
    FLensDeactivedDelegate OnLenseDeactivated;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SwitchTime;
    TSubclassOf<UStatusEffect> GammaContaminationSTE;
    TSubclassOf<UStatusEffect> GammaContaminationZoneSTE;
    float GammaContaminationRange;
    TSubclassOf<ABoil> ExplodableBlisterClass;
    float BlisteringNecrosisChance;
    float MinTimeBetweenBlisteringNecrosis;
    TSubclassOf<UStatusEffect> FireEffect;
    TArray<TSubclassOf<UStatusEffect>> NeuroEffects;
    TSubclassOf<UStatusEffect> NeuroToSpread;
    TSubclassOf<UStatusEffect> SlowEffect;
    UNiagaraSystem* ImpactParticleEnemies;
    UNiagaraSystem* ImpactParticleTerrain;
    UNiagaraSystem* NeuroSpreadParticles;
    UFXSystemAsset* P_NeuroSpreadParticles;
    USoundCue* NeuroSpreadSound;
    UNiagaraSystem* MicrowaveMuzzle;
    UNiagaraComponent* MuzzleComp;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSet<AActor*> ActorsInCapsule;
    float WeaponRange;
    float ShotWidth;
    float DamageInterval;
    float KilledTargetsExplosionChance;
    UNiagaraSystem* ExplosionOCSystem;
    float NeuroSpreadRadius;
    FMicrowaveLense WideLense;
    FMicrowaveLense FocusLense;
    float TemperatureAmplification;
    bool RadiantSuperheaterActive;
    float RadiantSuperheaterFrostShockChance;
    float RadiantSuperheaterHeatShockChance;
    float RadiantSuperheaterMinColdDamage;
    float RadiantSuperheaterMinHeatDamage;
    float RadiantSuperheaterFrostTransferFactor;
    float RadiantSuperheaterHeatTransferFactor;
    float ColdTempAmpMultiplier;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UElementComponent> RadiantSuperheaterTarget;
    bool SlowOnHit;
    TSubclassOf<AActor> HeatSink;
    AMicrowaveWeapon(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void UpdateMuzzleAnim(bool InIsFiring);
    void SpawnExplosiveBoil(UPrimitiveComponent* Target, const FMultiHitscanHit& Hit);
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void ShowBoilerRayExplosion_Server(FVector_NetQuantize Location, FRotator Rotation);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void ShowBoilerRayExplosion(FVector_NetQuantize Location, FRotator Rotation);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetLensePower(float lensepower);
    void OnTargetKilled(AActor* Target, UFSDPhysicalMaterial* PhysMat, bool wasDirectHit);
    void OnShowHitEffect(const FVector& ImpactPoint, const FVector& ImpactNormal, bool hitEnemy);
    void OnServerHitscanHit(const FMultiHitScanHits& Hits);
    void OnRadiantSuperHeaterAoe();
    void OnPushedDamageEffect(UHealthComponentBase* healthComp);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HeatUpdated(float SmoothedTemperature);
    void EndCharacterOverheatAnim();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowNeuroSpread(const FVector& Location);
};
