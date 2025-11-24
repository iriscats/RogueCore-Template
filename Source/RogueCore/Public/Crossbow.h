#pragma once
#include "CoreMinimal.h"
#include "AmmoDrivenWeapon.h"
#include "ECrossbowSwitchState.h"
#include "ProjectileSwitch.h"
#include "Templates/SubclassOf.h"
#include "Crossbow.generated.h"


class AActor;
class ACrossbowProjectileStuck;
class AProjectileBase;
class UAnimMontage;
class UProjectileLauncherBaseComponent;
class URecallableProjectileComponent;
class USoundCue;
class UStaticMesh;
class UStaticMeshComponent;
class UStatusEffect;
UCLASS(Blueprintable, NoExport)
class ACrossbow : public AAmmoDrivenWeapon {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDefaultArrowEquippedChanged, bool, InDefaultArrow);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDefaultArrowEquippedChanged OnDefaultArrowEquippedChanged;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FullDamageSpeed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AProjectileBase> DefaultArrow;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    TSubclassOf<AProjectileBase> SpecialArrow;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float SpecialStatusEffectBonusTimeScale;
protected:
    TSubclassOf<UStatusEffect> BattleFrenzyStatusEffect;
    TSubclassOf<ACrossbowProjectileStuck> BasicSpawnableStuckProjectile;
    int32 SpecialAmmoMax;
    float SwitchTime;
    bool CanTrifork;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_IsDefaultArrowEquipped, meta=(AllowPrivateAccess=true))
    bool IsDefaultArrowEquipped;
    float RecallProgress;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* AnimatedFPMesh;
    UStaticMeshComponent* AnimatedTPMesh;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SwitchIsQueued, meta=(AllowPrivateAccess=true))
    bool SwitchIsQueued;
    UPROPERTY(EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    ECrossbowSwitchState SwitchState;
    float OutOfAmmoSwapDelay;
    TSubclassOf<AActor> AnimatedArrowSpawnable;
    float ExtraShotAngleDifference;
    URecallableProjectileComponent* HoveringRecallable;
    float SwitchTimeCof;
    UStaticMesh* TriforkArrowMesh;
    UStaticMesh* QuintPackArrowMesh;
    TArray<FProjectileSwitch> GearStatArrows;
    UAnimMontage* SwitchMontage;
    UAnimMontage* SwitchMontage_TP;
    UAnimMontage* CharacterSwitchMontage;
    UAnimMontage* ReloadMontage;
    UAnimMontage* ReloadMontage_TP;
    UAnimMontage* CharacterReloadMontage;
    TArray<USoundCue*> ReloadSoundCues;
    ACrossbow(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void UpdateRecallProgress();
    UFUNCTION(BlueprintCallable)
    void StartAmmoSwitch();
    void SetAnimatedTPMeshComponentFromBP(AActor* animatedArrow);
    void SetAnimatedTPMeshComponent(UStaticMeshComponent* Component);
    void SetAnimatedFPMeshComponentFromBP(AActor* animatedArrow);
    void SetAnimatedFPMeshComponent(UStaticMeshComponent* Component);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_UpdateRetrievableArrows(const int32& defaultAmmo, const int32& specialAmmo);
    UFUNCTION(Reliable, Server)
    void Server_SwitchAmmoType(UProjectileLauncherBaseComponent* projectileLauncher, const ECrossbowSwitchState State);
    void Server_SetSwitchIsQueued(bool IsQueued);
    UFUNCTION()
    void OnRep_SwitchIsQueued();
    UFUNCTION()
    void OnRep_IsDefaultArrowEquipped();
    void OnProjectileFired(AProjectileBase* Projectile);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTotalArrowCount(bool InDefaultArrowCount) const;
    float GetSpecialArrowEffectDuration(const TSubclassOf<UStatusEffect>& Effect) const;
    bool GetIsDefaultArrowEquipped() const;
    void DestroyActor(AActor* Actor);
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_RefillSpecialAmmo(float percentage);
    void Client_CallAddSpecialAmmo(const int32& amount);
    void Client_CallAddDefaultAmmo(const int32& amount);
};
