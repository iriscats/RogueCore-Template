#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Engine/NetSerialization.h"
#include "AmmoDrivenWeapon.h"
#include "DecalData.h"
#include "Templates/SubclassOf.h"
#include "FlameThrowerItem.generated.h"

class AActor;
class UDamageComponent;
class UFSDPhysicalMaterial;
class UFXSystemAsset;
class UFXSystemComponent;
class UHealthComponentBase;
class UItemUpgrade;
class UMotionAudioController;
class UPrimitiveComponent;
class UProjectileLauncherBaseComponent;
class USoundCue;
class UStatusEffect;
class UStickyFlameSpawner;
UCLASS(Abstract, Blueprintable, NoExport)
class AFlameThrowerItem : public AAmmoDrivenWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UFXSystemComponent* FlameParticleComponent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDamageComponent* DamageComponent;
    UStickyFlameSpawner* StickyFlames;
    UDamageComponent* AoEHeatDamageComponent;
    UDamageComponent* ExplodingTargetsDamageComponent;
    UMotionAudioController* MotionAudio;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ShotCostProjectile;
    FDecalData ImpactDecal;
    float DecalDelay;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CurrentDecalDelay;
 
    UFXSystemAsset* ImpactParticles;
    UFXSystemComponent* ImpactParticleInstance;
    UFXSystemAsset* FP_LongReachParticles;
    UFXSystemAsset* TP_LongReachParticles;
    float VeryLongReachThreshold;
    UFXSystemAsset* FP_VeryLongReachParticles;
    UFXSystemAsset* TP_VeryLongReachParticles;
    TArray<FName> FlameParameterNames;
    float DamageSphereRadius;
    float MaxFlameDistance;
    float FlameGrowthPerSecond;
    float FlameEndPointResponsiveness;
    float FlameIntensityPerSecond;
    TSubclassOf<UStatusEffect> OnFireStatusEffect;
    float ChanceToFleeOnDamage;
    float MeltPointRadius;
    float MeltPointBuildTime;
    float MeltCarveTime;
    UFXSystemAsset* MeltSteamParticle;
    TArray<UItemUpgrade*> upgrades;
    bool LongReachEnabled;
    bool AoEHeatEnabled;
    float KilledTargetsExplosionChance;
    float ShowDamageParticle;
    UFXSystemAsset* DamangeTargetsParticles;
    UFXSystemAsset* KilledTargetsExplodingParticles;
    USoundCue* KilledTargetsExplodingSound;
    UProjectileLauncherBaseComponent* ProjectileLancher;
    AFlameThrowerItem(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void TriggerAoEHeat();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerMeltIce(const TArray<FVector>& meltPoints);
    UFUNCTION(Server, Reliable)
    void ServerDoDamage(FVector_NetQuantize Start, FVector_NetQuantize End);
    void OnTargetKilled(AActor* Target, UFSDPhysicalMaterial* PhysMat, bool wasDirectHit);
    void OnTargetDamaged(UHealthComponentBase* Health, float amount, UPrimitiveComponent* HitComponent, UFSDPhysicalMaterial* PhysicalMaterial);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_ShowTargetBurstIntoFire(FVector_NetQuantize Location, FRotator Rotation);
    UFUNCTION(NetMulticast, Unreliable)
    void All_FlameFeedback(FVector_NetQuantize Location, FRotator Rotation);
};
