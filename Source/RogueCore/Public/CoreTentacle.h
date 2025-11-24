#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CoreTentacleMovementTarget.h"
#include "CoreTentacleSwayTarget.h"
#include "ECoreTentacleState.h"
#include "TentacleBase.h"
#include "TriggerAI.h"
#include "CoreTentacle.generated.h"

class UDebrisPositioning;
UCLASS(Abstract, Blueprintable, NoExport)
class ROGUECORE_API ACoreTentacle : public ATentacleBase, public ITriggerAI {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_MovementTarget, meta=(AllowPrivateAccess=true))
    FCoreTentacleMovementTarget MovementTarget;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    ECoreTentacleState TentacleState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FCoreTentacleSwayTarget SwayTarget;
    void SetTentacleState(const ECoreTentacleState NewState);
    void SetSwayTarget(const FCoreTentacleSwayTarget& Target, const bool SwayImmediately);
    void SetMovementTarget(const FCoreTentacleMovementTarget& Target);
    void OnRep_MovementTarget();
    ECoreTentacleState GetTentacleState() const;
    FCoreTentacleMovementTarget GetMovementTarget() const;
    // Fix for true pure virtual functions not being implemented
};