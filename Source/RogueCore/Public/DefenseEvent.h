#pragma once
#include "CoreMinimal.h"
#include "GameEvent.h"
#include "Templates/SubclassOf.h"
#include "DefenseEvent.generated.h"

class UWidget;
UCLASS(Blueprintable)
class ADefenseEvent : public AGameEvent {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefendDuration;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Progress, meta=(AllowPrivateAccess=true))
    float Progress;

 
    TSubclassOf<UWidget> DefendWidget;
    ADefenseEvent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_Progress(float OldValue);
};
