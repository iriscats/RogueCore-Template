#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Curves/CurveFloat.h"
#include "EInputKeys.h"
#include "ERobotState.h"
#include "EnemyDeepPathfinderCharacter.h"
#include "IntroductionStartedDelegate.h"
#include "RobotShieldSwitchSigDelegate.h"
#include "RobotStateChangedSigDelegate.h"
#include "Templates/SubclassOf.h"
#include "WeaponFireOwner.h"
#include "ConvertedRobot.generated.h"

class AActor;
class AParasiteEnemy;
class APawn;
class APlayerCharacter;
class AProjectile;
class UAnimSequenceBase;
class UAudioComponent;
class UDamageComponent;
class UEnemyComponent;
class UFXSystemAsset;
class UHitscanComponent;
class UOutlineComponent;
class UPawnStatsComponent;
class UPointLightComponent;
class USceneComponent;
class USingleUsableComponent;
class USkeletalMeshComponent;
class USoundBase;
class USoundCue;
class USpotLightComponent;
class UStaticMeshComponent;
UCLASS(Blueprintable, NoExport)
class AConvertedRobot : public AEnemyDeepPathfinderCharacter, public IWeaponFireOwner {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEnemyComponent* EnemyComponent;

    UPawnStatsComponent* PawnStats;
    UOutlineComponent* Outline;
    UHitscanComponent* HitScan;
    USingleUsableComponent* usable;
    USceneComponent* TurretRoot;
    USkeletalMeshComponent* TurretMesh;
    UPointLightComponent* MuzzleFlash;
    USpotLightComponent* SpotLight;
    UStaticMeshComponent* LightCone;
    UStaticMeshComponent* LaserBeam;
    USceneComponent* ShieldRoot;
    UStaticMeshComponent* InnerShield;
    UStaticMeshComponent* OuterShield;
    UAudioComponent* PulsatingSoundComp;
    UAudioComponent* LaserWarningSound;
    UDamageComponent* Damage;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRobotStateChangedSig OnStateChanged;
    FRobotShieldSwitchSig OnShieldChanged;
    FIntroductionStarted OnIntroductionStart;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool ForceSit;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundBase* LaserSound;
    USoundBase* LastPowerDownSound;
    USoundBase* PowerUpSound;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAudioComponent> LaserSoundComp;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsIntroducting, meta=(AllowPrivateAccess=true))
    bool IsIntroducing;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool ReplaceBurstAttack;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsFiring, meta=(AllowPrivateAccess=true))
    bool IsFiring;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SpinTurret, meta=(AllowPrivateAccess=true))
    bool SpinTurret;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UAudioComponent* ShootSoundInstance;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_TeamState, meta=(AllowPrivateAccess=true))
    ERobotState TeamState;

protected:
    bool IntroductionDone;
    bool IsGrowingShield;
    float AimDownwardsOffset;
    float BigShieldScale;
    float SmallShieldScale;
    float ShieldGrowthRate;
    float LerpExp;
    float MinimumShieldSize;
    float TargetShieldSize;
    float IdleRotationSpeed;
    float LaserScaleRate;
    float MaxSearchAngle;
    bool DoSpecialWhenEnemy;
    bool DoSpecialWhenFriendly;
    bool PerfectTrackingWhenEnemy;
    bool PerfectTrackingWhenFriendly;
    USoundBase* GrenadeFireSound;
    UFXSystemAsset* GrenadeFireParticle;
    float TurretSpinSpeed;
    TArray<AActor*> Parasites;
    int32 SpawnParasiteNumer;
    int32 MaxParasiteSlots;
    float ChanceToSpawnParasite;
    TSubclassOf<AParasiteEnemy> ParasiteClass;
    TSubclassOf<AProjectile> SpecialAttackProjectile;
    TSubclassOf<AProjectile> FriendlyProjectile;
    bool HasLockedOn;
    USoundBase* TargetingSound;
    UAnimSequenceBase* GrenadeShotAnimation;
    float LockOnTime;
    USoundCue* ShootSound;
    float ShootSoundFadeout;
    USoundCue* ShootSoundTail;
    UFXSystemAsset* MuzzleEffect;
    UFXSystemAsset* TracerEffect;
    FRuntimeFloatCurve MuzzleLightCurve;
    float GunRange;
    float FireRate;
    float GrenadeFireRate;
    float BurstCooldown;
    int32 MinBurst;
    int32 MaxBurst;
    float TurretLerpSpeed;
    float DamageWhenFriendly;
    float FriendlyFriendlyFireMultiplier;
    bool StartedSpecialAttack;

private:
    bool IsWalking;
    UStaticMeshComponent* TurretRotation;

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsDoingSpecialAttack, meta=(AllowPrivateAccess=true))
    bool IsDoingSpecialAttack;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Target, meta=(AllowPrivateAccess=true))
    AActor* CurrentTarget;
    AConvertedRobot(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void UpdateGunsInsideTerrain();
    void StartBossFight();
    void ParasiteDamaged(float aDamage);
    void OnWeaponsFired(const FVector& aHitResult);
    void OnUsed(APlayerCharacter* aUser, EInputKeys Key);
    void OnSeePawn(APawn* aPawn);
    UFUNCTION()
    void OnRep_TeamState();
    UFUNCTION()
    void OnRep_Target();
    UFUNCTION()
    void OnRep_SpinTurret();
    UFUNCTION()
    void OnRep_IsIntroducting();
    UFUNCTION()
    void OnRep_IsFiring();
    UFUNCTION()
    void OnRep_IsDoingSpecialAttack();
    void OnParasiteDeath(AActor* aParasiteEnemy);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ERobotState GetTeamState() const;
    FVector GetPlayerMediumPoint() const;
    TArray<AActor*> GetParasites() const;
    bool GetHasPoweredDown() const;
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void DestroyAttatchPoint(USceneComponent* aComponent);
    void CannonEffects_Implementation();
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void BP_OnStateChanged(ERobotState NewTeamState);
public:
    void BP_OnShieldChanged(bool isGrowing);
    void BP_OnInstroduce();
    // Fix for true pure virtual functions not being implemented
    APlayerCharacter* GetPlayerCharacter() const override PURE_VIRTUAL(GetPlayerCharacter, return NULL;);
    FQuat GetMuzzleQuat() const override PURE_VIRTUAL(GetMuzzleQuat, return FQuat{};);
    FVector GetMuzzleLocation() const override PURE_VIRTUAL(GetMuzzleLocation, return FVector{};);
    bool GetIsLocallyControlled() const override PURE_VIRTUAL(GetIsLocallyControlled, return false;);
    bool GetIsFirstPerson() const override PURE_VIRTUAL(GetIsFirstPerson, return false;);
};
