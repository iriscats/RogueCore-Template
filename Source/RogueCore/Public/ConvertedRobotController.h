#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EnemyAIController.h"
#include "BehaviorTree/BehaviorTree.h"
#include "ConvertedRobotController.generated.h"
UCLASS(Blueprintable, NoExport)
class AConvertedRobotController : public AEnemyAIController {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagQuery FriendlyTargetingQuery;

    float CheckRangeInterval;
    float MaxTimeInRange;
    float PersonalSpaceRange;
    float SpecialAttackRange;
    float SpecialAttackFireRate;
    float WaitBeforeSpecial;
    float WaitAfterSpecial;
    float MinSpecialAttackCooldown;
    float MaxSpecialAttackCooldown;
    UBehaviorTree* BehaviourTree;
    float UpdateTargetInterval;
    float PowerDownAfterSeconds;
    AConvertedRobotController(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ResetCloseTimer();
};
