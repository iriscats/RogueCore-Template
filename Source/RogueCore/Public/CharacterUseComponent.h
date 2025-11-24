#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "BeginUsingDelegateDelegate.h"
#include "CharacterUseState.h"
#include "DepositingEventDelegate.h"
#include "ECustomUsableType.h"
#include "EInputKeys.h"
#include "EndUsingDelegateDelegate.h"
#include "CharacterUseComponent.generated.h"

class AActor;
class APlayerCharacter;
class UUsableComponent;
class UUsableComponentBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UCharacterUseComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBeginUsingDelegate OnBeginHoveringEvent;
    
    FEndUsingDelegate OnEndHoveringEvent;
    FBeginUsingDelegate OnBeginUsingEvent;
    FEndUsingDelegate OnEndUsingEvent;
    FDepositingEvent OnDepositingBegin;
    FDepositingEvent OnDepositingEnd;
    FBeginUsingDelegate OnUsableTriggered;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UseDistance;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    FCharacterUseState State;
    FCharacterUseState LocalState;
    FCharacterUseState LastRequestedState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUsableComponentBase* LastBeginUseUsable;
    TArray<UUsableComponentBase*> UsableComponentsCache;
    UUsableComponentBase* HoveringUsable;
    UCharacterUseComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void Server_SetState(const FCharacterUseState& NewState);
    void Server_OnUsedBy_Implementation(UUsableComponent* usable, APlayerCharacter* User, EInputKeys Key);
    UFUNCTION(BlueprintCallable)
    void RemoveCustomUsableComponent(UUsableComponentBase* usable);
    UFUNCTION()
    void OnRep_State(const FCharacterUseState& oldState);
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void NotifyUsableUsed(UUsableComponentBase* usable);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLookingAtUsable() const;
    bool IsLookingAtDepositable() const;
    float GetUseProgress() const;
    AActor* GetLookingAtActor() const;
    bool GetIsUsing();
    bool GetIsDepositing();
    UUsableComponentBase* GetHoveringUsable() const;
    UUsableComponentBase* GetActiveUsable() const;
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void Client_OnUsedBy(UUsableComponent* InUsable, EInputKeys Key);
    bool CheckPlayerHasPermission(UUsableComponentBase* usable);
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_UseEnded(const FCharacterUseState& oldState);
    void AddCustomUsableComponent(UUsableComponentBase* usable, ECustomUsableType eType);
};
