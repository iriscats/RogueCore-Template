#pragma once
#include "CoreMinimal.h"
#include "AbilityItem.h"
#include "DroneControllerUseInfo.h"
#include "EAbilityDroneState.h"
#include "ECharacterState.h"
#include "Templates/SubclassOf.h"
#include "AbilityDroneController.generated.h"

class AAbilityDrone;
class AActor;
class UAnimMontage;
class UDialogDataAsset;
class UInputComponent;
class USkeletalMeshComponent;
class UStatusEffect;
UCLASS(Blueprintable, NoExport)
class AAbilityDroneController : public AAbilityItem {
    GENERATED_BODY()
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FAbilityDroneControllerDelegate);
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USkeletalMeshComponent* FPBirdMesh;
    USkeletalMeshComponent* TPBirdMesh;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UStatusEffect> SentOutStatus;
    UAnimMontage* FP_PetDrone;
    UAnimMontage* TP_PetDrone;
    UAnimMontage* Bird_Pet;
    UAnimMontage* Bird_Equip;
    UAnimMontage* Item_AlternateEquip;
    UAnimMontage* Bird_ReceivedBird;
    UAnimMontage* Item_ReceivedBird;
    UAnimMontage* FP_ReceivedBird;
    UAnimMontage* TP_ReceivedBird;
    UAnimMontage* Item_Activation;
    UAnimMontage* RecallAnim;
    UAnimMontage* TP_RecallAnim;
    UAnimMontage* FP_ReactivateDroneAnim;
    UAnimMontage* TP_ReactivateDroneAnim;
    UAnimMontage* Bird_JumpStart;
    UAnimMontage* Bird_JumpEnd;
    UDialogDataAsset* PrimaryCommandedShout;
    UDialogDataAsset* SecondaryCommandedShout;
    float Range;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<AActor> AttackTarget;
    TWeakObjectPtr<AActor> ReviveTarget;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_DroneInstances, meta=(AllowPrivateAccess=true))
    TArray<AAbilityDrone*> DroneInstances;
    TSubclassOf<AAbilityDrone> DroneClass;
    float RangeForReviveWithoutLineOfSight;
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAbilityDroneControllerDelegate OnReviveTargetChanged;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UInputComponent* PlayerInputComponent;
    AAbilityDroneController(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_UseSecondary(FDroneControllerUseInfo droneInfo);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_UsePrimary(FDroneControllerUseInfo droneInfo);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ShowRecall(bool sentOut);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_ShowActivation(bool sentOut);
    UFUNCTION(BlueprintCallable, Server, Unreliable)
    void Server_RecallDrones();
    UFUNCTION(BlueprintCallable)
    void OnUsingFinished();
    UFUNCTION()
    void OnRep_DroneInstances();
    void OnDroneStateChanged(EAbilityDroneState State);
 
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDroneReviveActivated();
public:
    void OnDroneOrder(bool sentOut);
    void OnDroneDestroyed(AActor* drone);
    void OnDroneAttacked();
    void OnCharacterStateChanged(ECharacterState NewState);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetReviveTarget() const;
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_ShowRecall(bool sentOut);
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_ShowActivation(bool sentOut);
};
