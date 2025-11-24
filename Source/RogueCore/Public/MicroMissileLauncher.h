#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "EMicroMissileLauncherFireMode.h"
#include "MicroMissileLauncher.generated.h"

class UAnimMontage;
class UChargedProjectileLauncherComponent;
class USoundCue;
UCLASS(Abstract, Blueprintable, NoExport)
class AMicroMissileLauncher : public AAmmoDrivenWeapon {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_MML_ClipCount, meta=(AllowPrivateAccess=true))

    int32 MML_ClipCount;

    AMicroMissileLauncher(const FObjectInitializer& ObjectInitializer);



public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FChargingDelegate);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FChargingDelegate OnStartCharging;
    FChargingDelegate OnEndCharging;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UChargedProjectileLauncherComponent* LauncherComponent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> MuzzleNames;
    float ChargeTime;
    int32 ChargeMaxFireCount;
    float BuckShotDelay;
    float ShotDirectionHorizontalDegreeOffset;
    float ShotDirectionVerticleDegreeOffset;
    EMicroMissileLauncherFireMode FireMode;
    bool DisableHomingOnRelease;
    float MaxHomingProjectiles;
    UAnimMontage* WPN_Fire_Empty_Mag;
    UAnimMontage* WPN_Fire_Level2;
    UAnimMontage* WPN_Fire_Level2_Empty_Mag;
    UAnimMontage* WPN_Fire_Level3;
    UAnimMontage* WPN_Fire_Level3_Empty_Mag;
    UAnimMontage* WPN_Mag_Feed;
    UAnimMontage* WPN_Mag_And_Barrel_Feed;
    USoundCue* ChargedMissileFireSound;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_MML_ClipCount, meta=(AllowPrivateAccess=true))
    int32 MML_ClipCount;
    AMicroMissileLauncher(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetIsCharging(bool isCharging);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetChargedMissile(bool isCharged);
    UFUNCTION(BlueprintCallable)
    void OnRep_MML_ClipCount();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNextShotBuckShot();
    int32 GetChargeCurrentFireCount();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_SetChargedMissile(bool isCharged);
};
