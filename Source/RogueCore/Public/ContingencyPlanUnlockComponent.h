#pragma once
#include "CoreMinimal.h"
#include "Engine/TimerHandle.h"
#include "DelegateDelegate.h"
#include "OnGameStateDelegateDelegate.h"
#include "PerkInputUnlockComponent.h"
#include "ContingencyPlanUnlockComponent.generated.h"

class AFSDGameState;
class UHealthComponentBase;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API UContingencyPlanUnlockComponent : public UPerkInputUnlockComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDelegate OnContingencyStarted;
    
    FDelegate OnContingencyEnded;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGameStateDelegate OnGameStateChangedDelegate;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle Handle_Timeout;
    FTimerHandle Handle_ActivationDelay;
    float ActivationDelay;
    bool Used;
    UContingencyPlanUnlockComponent(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void StartContingencyPlan();
    void SetUsed(bool NewValue);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void Receive_Triggered();
    void Receive_StartContingencyPlan();
    void OnOwnerRevived();
    void OnOwnerDied(UHealthComponentBase* Health);
    void OnGameStateChanged(AFSDGameState* GameState);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEffectActive() const;
    void EndContingencyPlan();
    UFUNCTION(BlueprintCallable, NetMulticast, Unreliable)
    void All_Triggered();
    void All_OnContingencyStarted_Implementation();
    void All_OnContingencyEnded_Implementation();
};
