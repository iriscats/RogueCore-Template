#pragma once
#include "CoreMinimal.h"
#include "ENisseState.h"
#include "SimpleMovingEnemyAnimInstance.h"
#include "NisseAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UNisseAnimInstance : public USimpleMovingEnemyAnimInstance {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ENisseState State;
    
    UNisseAnimInstance();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsWalking() const;
    bool IsRunning() const;
    bool IsNotWalking() const;
    bool IsNotRunning() const;
    bool IsNotIdle() const;
    bool IsNotFrozen() const;
    bool IsIdle() const;
    bool IsFrozen() const;
};
