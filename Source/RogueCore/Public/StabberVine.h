#pragma once
#include "CoreMinimal.h"
#include "TentacleBase.h"
#include "TentacleTarget.h"
#include "StabberVine.generated.h"

UCLASS(Abstract, Blueprintable)
class AStabberVine : public ATentacleBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_DesiredTarget, meta=(AllowPrivateAccess=true))
    FTentacleTarget DesiredTarget;
    
    AStabberVine(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void OnRep_DesiredTarget();
};
