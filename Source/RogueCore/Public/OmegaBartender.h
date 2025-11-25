#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "AnimationWeight.h"
#include "ArmAnimation.h"
#include "EBartenderAnim.h"
#include "OnNewGymGoalDelegateDelegate.h"
#include "OnNewSpecialOrderSignatureDelegate.h"
#include "OmegaBartender.generated.h"

class ADrinkableActor;
class APlayerCharacter;
class UAnimMontage;
class UDrinkableDataAsset;
class UResourceData;
class USceneComponent;
UCLASS(Blueprintable)
class ROGUECORE_API AOmegaBartender : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnNewSpecialOrderSignature OnNewSpecialOrder;
    
    FOnNewGymGoalDelegate OnNewGymGoal;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_GymCurrencyAmount, meta=(AllowPrivateAccess=true))
    TArray<int32> GymCurrencyAmount;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_GymCurrencyData, meta=(AllowPrivateAccess=true))
    TArray<UResourceData*> GymCurrencyData;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MugSocketName;
    FName DetachNotifyName;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Mugs, meta=(AllowPrivateAccess=true))
    TArray<ADrinkableActor*> Mugs;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<bool> EmptySlot;
    UDrinkableDataAsset* CurrentOrder;
    UDrinkableDataAsset* SpecialOrder;
    int32 CurrentIdleMontageIndex;
    int32 CurrentPourMontageIndex;
    int32 DrinkAmount;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_BartenderAnimationState, meta=(AllowPrivateAccess=true))
    EBartenderAnim BartenderAnimationState;
    TArray<FAnimationWeight> OmegaIdle;
    TArray<FArmAnimation> OmegaIdleArm;
    TArray<FAnimationWeight> OmegaPourArm1;
    TArray<FAnimationWeight> OmegaPourArm2;
    TArray<FAnimationWeight> OmegaPourArm3;
    TArray<FAnimationWeight> OmegaPourArm4;
    UAnimMontage* OmegaSalute;
    float SaluteLoseTime;
    float SaluteCooldown;
    int32 SalutesToMakeOmegaSalute;
    AOmegaBartender(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void ValidCheckPlayersInside();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void StartOrder(UDrinkableDataAsset* Order);
    void SpawnMugInHand(int32 Index, USceneComponent* Parent);
    void SetSpecialOrder(UDrinkableDataAsset* Order);
    void SetMug(ADrinkableActor* Mug, int32 Index);
    void SetDrink(UDrinkableDataAsset* Drink);
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_PlayerSaluted();
    UFUNCTION(Reliable, Server)
    void Server_MugTaken(ADrinkableActor* Mug);
    void RemovePlayerInside(APlayerCharacter* Player);
    void PlayOmegaSaluteMontage(UAnimMontage* Montage);
    void PlayOmegaPourMontage(UAnimMontage* Montage);
    void PlayOmegaIdleMontage(int32 Index);
    void PlayFillAnimation(int32 Index, UAnimMontage* Montage);
    void PlaceOrder();
    void PickNewIdle();
    UFUNCTION()
    void OnRep_Mugs();
    UFUNCTION()
    void OnRep_GymCurrencyData();
    UFUNCTION()
    void OnRep_GymCurrencyAmount();
    UFUNCTION()
    void OnRep_BartenderAnimationState();
    void NotifyDetachMug(FName NotifyName, int32 Index);
    void MugTaken(ADrinkableActor* Mug);
    UAnimMontage* GetIdleMontage(int32 Index);
    UAnimMontage* GetIdleArmMontage(int32 MontageIndex, int32 ArmIndex);
    TArray<bool> GetEmptySlots();
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_DetachMug(int32 Index, const FTransform& Transform);
    void ChangeBartenderAnimState(EBartenderAnim State);
    void BroadcastNewGymGoal(UDrinkableDataAsset* Order);
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void All_MugFilled(int32 Index);
    UFUNCTION(NetMulticast, Reliable)
    void All_ChangeMugSlot(int32 Index, bool Empty);
    void AddPlayerInside(APlayerCharacter* Player);
    void ActivateButton();
};
