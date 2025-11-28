#pragma once
#include "CoreMinimal.h"

#include "Engine/NetSerialization.h"
#include "AmmoDrivenWeapon.h"
#include "DecalData.h"
#include "CryosprayItem.generated.h"

class AProjectileBase;
class UDamageComponent;
class UFSDAudioComponent;
class UFSDPhysicalMaterial;
class UFXSystemAsset;
class UFXSystemComponent;
class UHealthComponentBase;
class UItemUpgrade;
class UMotionAudioController;
class UNiagaraComponent;
class UNiagaraSystem;
class UPrimitiveComponent;
class UProjectileLauncherComponent;
class UStickyFlameSpawner;
UCLASS(Abstract, Blueprintable)
class ACryosprayItem : public AAmmoDrivenWeapon {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UProjectileLauncherComponent* projectileLauncher;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFXSystemComponent* FlameParticleComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool PressurizedProjectileEnabled;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PressurizedProjectileDelay;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsCharging, meta=(AllowPrivateAccess=true))
    bool isCharging;
 
    UDamageComponent* DamageComponent;
    UStickyFlameSpawner* StickyFlames;
    UDamageComponent* AoEColdDamageComponent;
    UMotionAudioController* VelocityAudio;
    int32 PressurizeProjectileFullCost;
    UNiagaraSystem* ChargeupParticles;
    UNiagaraComponent* ChargeupParticleInstance;
    FDecalData ImpactDecal;
    float DecalDelay;
    UFXSystemAsset* ImpactParticles;
    UFXSystemComponent* ImpactParticleInstance;
    TArray<FName> FlameParameterNames;
    float DamageSphereRadius;
    float MaxFlameDistance;
    float FlameGrowthPerSecond;
    float FriendlyFireModifier;
    float ChargeupTime;
    float ChargeDownTime;
    float ChargeProgress;
    bool bRepressurerising;
    float RepressurerisingDoneAtPct;
    float ChargeUpFadeOutTime;
    UFSDAudioComponent* ChargeUpAudioComponent;
    float PressureTime;
    float PressureDropMultiplier;
    float PressureGainMultiplier;
    float CurrentPressure;
    float RePressureDuration;
    float RePressureProgress;
    TArray<UItemUpgrade*> upgrades;
    bool LongReachEnabled;
    bool AoEColdEnabled;
    ACryosprayItem(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerDoDamage(FVector_NetQuantize Start, FVector_NetQuantize End, uint8 Power);
    UFUNCTION(Reliable, Server)
    void Server_TriggerAoECold();
    UFUNCTION(Reliable, Server)
    void Server_PreLaunchProjectile();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveRepressurisingChanged(bool Value);
    UFUNCTION(BlueprintCallable)
    void OnTargetDamaged(UHealthComponentBase* Health, float amount, UPrimitiveComponent* HitComponent, UFSDPhysicalMaterial* PhysicalMaterial);
    UFUNCTION()
    void OnRep_IsCharging(bool OldValue);
    void OnProjectileSpawned(AProjectileBase* Projectile);
    void OnProjectileLaunched(const FVector& Location);
    void OnPressurizedPartileShoot();
    void OnPreProjectileLaunch();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_PreLaunchProjectile();
};
