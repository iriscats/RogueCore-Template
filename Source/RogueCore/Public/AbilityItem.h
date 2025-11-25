#pragma once
#include "CoreMinimal.h"
#include "DelegateDelegate.h"
#include "EItemActivationType.h"
#include "Item.h"
#include "SpawnActor.h"
#include "Templates/SubclassOf.h"
#include "Upgradable.h"
#include "AbilityItem.generated.h"

class AProjectileBase;
class UAbilityComponent;
class UAnimMontage;
class UItemCharacterAnimationSet;
class UProjectileAbilityUpgrade;
class USkeletalMeshComponent;
class UUpperBodyCharacterAnimationSet;
UCLASS(Blueprintable, NoExport)
class AAbilityItem : public AItem, public IUpgradable {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimMontage* Item_EquipAnimation;
    
    UAnimMontage* FP_EquipAnimation;
    UAnimMontage* TP_EquipAnimation;
    UAnimMontage* FP_ActivationAnimation;
    UAnimMontage* TP_ActivationAnimation;
    UAnimMontage* FP_IdleAnimation;
    UAnimMontage* TP_IdleAnimation;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnAbilityPressed_Delegate;
    FDelegate OnAbilityReleased_Delegate;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UAbilityComponent> Ability;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* FPSuitMesh;
    USkeletalMeshComponent* TPSuitMesh;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSpawnActor> OnActivationSpawnActorUpgrades;
    TArray<TSubclassOf<AProjectileBase>> OnActivationProjectileUpgrades;
    TArray<UProjectileAbilityUpgrade*> ProjectileUpgrades;
 
    float UnEquipTime;
    float ActivationDelay;
    int32 EquipCost;
    float EquipDuration;
    UItemCharacterAnimationSet* CharacterAnimationSet;
    UUpperBodyCharacterAnimationSet* UpperBodyCharacterAnimationSet;
    EItemActivationType ActivationType;
    bool DeactivateOnUnequip;
    bool UnEquipOnActivation;
    AAbilityItem(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_ChargesChanged(int32 charges);
    void OnReceiveEquippedFinished();
    UFUNCTION(BlueprintCallable)
    void OnEquipFinished();
    void OnDeactivated();
    void OnChargesChanged(int32 charges);
    void OnActivated();
    void OnAbilityReleased();
    void OnAbilityPressed();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    USkeletalMeshComponent* GetTPMesh() const;
    USkeletalMeshComponent* GetFPMesh() const;
    void AnimFinished(UAnimMontage* Montage, bool interrupted);
    // Fix for true pure virtual functions not being implemented
};
