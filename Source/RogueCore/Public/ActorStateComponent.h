#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "StateDelegateDelegate.h"
#include "StateTickDelegateDelegate.h"
#include "ActorStateComponent.generated.h"

class UActorStateComponent;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class UActorStateComponent : public UActorComponent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))

    float StateActiveTime;

    UActorStateComponent(const FObjectInitializer& ObjectInitializer);

    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;



public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStateDelegate OnBeginState;
    
    FStateTickDelegate OnTickState;
    FStateDelegate OnEndState;
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, ReplicatedUsing=OnRep_CurrentState, meta=(AllowPrivateAccess=true))
    UActorStateComponent* CurrentState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UActorStateComponent* NextState;
    UActorStateComponent* MasterState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float StateActiveTime;
    UActorStateComponent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_CurrentState(UActorStateComponent* previousState);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsStateActive() const;
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void GotoState();
};
