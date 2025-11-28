#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EDefendPointState.h"
#include "EInputKeys.h"
#include "Templates/SubclassOf.h"
#include "DefensePointActor.generated.h"

class AGameEvent;
class APlayerCharacter;
class USingleUsableComponent;
UCLASS(Abstract, Blueprintable)
class ADefensePointActor : public AActor {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AGameEvent> DefenseEvent;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AGameEvent* ActiveDefenceEvent;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_DefendState, meta=(AllowPrivateAccess=true))
    EDefendPointState DefendState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USingleUsableComponent* DefendPointUsable;

 
    ADefensePointActor(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetState(EDefendPointState State);
    UFUNCTION()
    void OnRep_DefendState();
    void OnDefensePointActivated(APlayerCharacter* Player, EInputKeys Key);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void DefenseStart();
    void DefenseFail();
    void DefenseComplete();
};
