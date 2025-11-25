#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ERivalBombNodeState.h"
#include "Templates/SubclassOf.h"
#include "RivalBombNode.generated.h"

class APlayerCharacter;
class ARivalBomb;
class ARivalBombNode;
class ASplineCableActor;
class UHackingUsableComponent;
UCLASS(Blueprintable)
class ARivalBombNode : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FStateChangedDelegate, ARivalBombNode*, InBombNode, ERivalBombNodeState, InState);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStateChangedDelegate OnStateChanged;
 
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ASplineCableActor> RivalBombCable;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHackingUsableComponent* HackingUsable;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_State, meta=(AllowPrivateAccess=true))
    ERivalBombNodeState State;
    ASplineCableActor* BombCable;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    ARivalBomb* RivalBomb;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_RemainingHackTime, meta=(AllowPrivateAccess=true))
    float RemainingHackTime;
    float HackStartTime;
    int32 BombIndex;
    ARivalBombNode(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveStateUpdated();
    UFUNCTION(BlueprintCallable)
    void OnRep_State();
    UFUNCTION()
    void OnRep_RemainingHackTime() const;
    void OnNodeHackedByUser(APlayerCharacter* Player);
    void OnHackTimerTick();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRemainingTimePct() const;
};
