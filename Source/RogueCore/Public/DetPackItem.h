#pragma once
#include "CoreMinimal.h"
#include "AnimatedItem.h"
#include "Templates/SubclassOf.h"
#include "Upgradable.h"
#include "UpgradableGear.h"
#include "DetPackItem.generated.h"

class ADetPack;
class AItem;
class UAnimMontage;
class UCapacityHoldingItemAggregator;
class UDialogDataAsset;
class UForceFeedbackEffect;
class UItemUpgrade;
class USkeletalMeshComponent;
UCLASS(Blueprintable, NoExport)
class ADetPackItem : public AAnimatedItem, public IUpgradable, public IUpgradableGear {
    GENERATED_BODY()

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ADetPack> DetPackClass;
    
    TSubclassOf<AItem> LoadoutProxy;
    UAnimMontage* FPThrowMontage;
    UAnimMontage* TPThrowMontage;
    UAnimMontage* FP_DetonateAnim;
    UAnimMontage* WPN_DetonateAnim;
    UAnimMontage* FP_EquipDetonatorAnimation;
    UAnimMontage* WPN_EquipDetonatorAnimation;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* DetonatorFPMesh;
    USkeletalMeshComponent* DetonatorTPMesh;
    UForceFeedbackEffect* DetonatorTriggerForceFeedback;
    UCapacityHoldingItemAggregator* Capacity;
    float SupplyStatusWeight;
    float ThrowVelocity;
    float EnheiritOwnerVelocityScale;
    float ThrowAngle;
    float CooldownAfterThrow;
    float CooldownAfterDetonation;
    float ThrowDelay;
    float ThrowZOffset;
    UDialogDataAsset* ShoutDetPackPlaced;
    UDialogDataAsset* ShoutOutOfAmmo;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float CooldownLeft;
    TArray<ADetPack*> ThrownPacks;
    TArray<UItemUpgrade*> DetPackUpgrades;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_IsDetonatorOut, meta=(AllowPrivateAccess=true))
    bool IsDetonatorOut;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    bool HasThrownPack;
    ADetPackItem(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void Simulate_ThrowGrenade();
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ThrowGrenade();
    void Server_Detonate_Implementation();
    void Server_CycleItem_Implementation();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_OnRep_IsDetonatorOut();
    UFUNCTION(BlueprintCallable)
    void OnRep_IsDetonatorOut();
    void OnDetonatingFinished();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetCurrentGrenades() const;
    // Fix for true pure virtual functions not being implemented
};
