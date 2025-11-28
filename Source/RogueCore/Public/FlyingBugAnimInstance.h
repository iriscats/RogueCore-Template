#pragma once
#include "CoreMinimal.h"
#include "EFlyingBugDeathAnimationCategory.h"
#include "SimpleMovingEnemyAnimInstance.h"
#include "FlyingBugAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UFlyingBugAnimInstance : public USimpleMovingEnemyAnimInstance {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool IsInAttackMode;
    
    bool IsStaggered;
    EFlyingBugDeathAnimationCategory DeathAnimationCategory;
    UFlyingBugAnimInstance(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void SetDeathAnimation(EFlyingBugDeathAnimationCategory deathAnim);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsNotStaggered() const;
    bool IsNotInAttackMode() const;
};
