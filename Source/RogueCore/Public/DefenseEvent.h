#pragma once
#include "CoreMinimal.h"
#include "GameEvent.h"
#include "Templates/SubclassOf.h"
#include "DefenseEvent.generated.h"

class UWidget;
UCLASS(Blueprintable, NoExport)
class ADefenseEvent : public AGameEvent {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefendDuration;
    
    TSubclassOf<UWidget> DefendWidget;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_Progress, meta=(AllowPrivateAccess=true))
    float Progress;
    ADefenseEvent(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_Progress(float OldValue);
};
