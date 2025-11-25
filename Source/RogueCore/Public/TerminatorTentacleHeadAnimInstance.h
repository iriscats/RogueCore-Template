#pragma once
#include "CoreMinimal.h"
#include "EnemyAnimInstance.h"
#include "TerminatorTentacleHeadAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UTerminatorTentacleHeadAnimInstance : public UEnemyAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool Idle;

    bool Grabbing;
    bool Grabbed;
    UTerminatorTentacleHeadAnimInstance(const FObjectInitializer& ObjectInitializer);
};
