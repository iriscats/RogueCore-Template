#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "Engine/OverlapResult.h"
#include "GameplayTagContainer.h"
#include "AmmoCountChangedEventDelegate.h"
#include "LaserPointerTarget.h"
#include "SentryGunMuzzleSetup.h"
#include "Templates/SubclassOf.h"
#include "TracerData.h"
#include "Upgradable.h"
#include "WeaponFireOwner.h"
#include "SentryGun.generated.h"

class APlayerCharacter;
class AProjectile;
class UAudioComponent;
class UFXSystemAsset;
class UHealthComponentBase;
class USkeletalMeshComponent;
class USoundBase;
class USoundCue;
class UWeaponFireComponent;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API ASentryGun : public AActor, public IWeaponFireOwner, public IUpgradable {
    GENERATED_BODY()
    

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FEnabledChanged, bool, IsEnabled);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEnabledChanged OnEnabledChanged;
    FAmmoCountChangedEvent OnAmmoCountChanged;
    FAmmoCountChangedEvent OnMaxAmmoCountChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* SentryGunMesh;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FSentryGunMuzzleSetup> SentryGunMuzzels;
    TSubclassOf<AProjectile> ProjectileClass;
    USoundCue* ShootingSound;
    UFXSystemAsset* MuzzleFlash;
    FTracerData TracerData;
    UFXSystemAsset* Tracer;
    float MinTracerDistance;
    float AngleRestriction;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool Enabled;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FOverlapResult> OverlapCache;
    FRotator MinRotation;
    FRotator MaxRotation;
    float AquisitionRange;
    float RotationSpeed;
    float ShotCoolDown;
    float TargetLeading;
    int32 BurstCount;
    float BurstShotCoolDown;
    float IdleScanAngle;
    float IdleScanSpeed;
    float FinalShotFadeOut;
    USoundBase* AudioOnTurn;
    FGameplayTagContainer DissallowedTargetTags;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_AmmoCount, meta=(AllowPrivateAccess=true))
    int32 AmmoCount;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_MaxAmmoCount, meta=(AllowPrivateAccess=true))
    int32 MaxAmmoCount;
    float Damage;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    float TargetYaw;
    float TargetPitch;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, ReplicatedUsing=OnRep_LastTarget, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UHealthComponentBase> LastTarget;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UHealthComponentBase> PrioritizedTarget;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UWeaponFireComponent* WeaponFire;
    UAudioComponent* ShootingAudioComponent;
    ASentryGun(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void UseAmmo(int32 amount);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveAmmoChanged(int32 Delta, int32 CurrentAmount);
    UFUNCTION(BlueprintCallable)
    void OnRep_MaxAmmoCount(int32 OldCount);
    UFUNCTION()
    void OnRep_LastTarget();
    UFUNCTION()
    void OnRep_AmmoCount(int32 OldCount);
    void OnProjectileFired(const FVector& Location);
    void OnNewTargetRequested(const FLaserPointerTarget& HitInfo);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetMuzzleTransform() const;
    FName GetMuzzleName() const;
    int32 GetMaxAmmoCount() const;
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    float GetDeployProgress() const;
    float GetAmmoLeftPct() const;
    int32 GetAmmoLeft() const;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Force_Fire(AActor* Target);
    void AmmoSpent();
    // Fix for true pure virtual functions not being implemented
    APlayerCharacter* GetPlayerCharacter() const override PURE_VIRTUAL(GetPlayerCharacter, return NULL;);
    FQuat GetMuzzleQuat() const override PURE_VIRTUAL(GetMuzzleQuat, return FQuat{};);
    FVector GetMuzzleLocation() const override PURE_VIRTUAL(GetMuzzleLocation, return FVector{};);
    bool GetIsLocallyControlled() const override PURE_VIRTUAL(GetIsLocallyControlled, return false;);
    bool GetIsFirstPerson() const override PURE_VIRTUAL(GetIsFirstPerson, return false;);
};
