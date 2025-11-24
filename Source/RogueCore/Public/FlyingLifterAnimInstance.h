#pragma once
#include "CoreMinimal.h"
#include "EGrabberState.h"
#include "SimpleMovingEnemyAnimInstance.h"
#include "FlyingLifterAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UFlyingLifterAnimInstance : public USimpleMovingEnemyAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool HasGrabbedPlayer;
    
    bool ToChaseLock;
    bool ChaseToWanderLock;
    bool ToCarryLock;
    EGrabberState GrabberState;
    UFlyingLifterAnimInstance();
};
