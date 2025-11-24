#pragma once
#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "EnemyAIController.h"
#include "ConvertedRobotController.generated.h"

class UBehaviorTree;
UCLASS(Blueprintable, NoExport)
class AConvertedRobotController : public AEnemyAIController {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameplayTagQuery FriendlyTargetingQuery;
private:
    float UpdateTargetInterval;
    float PowerDownAfterSeconds;
    AConvertedRobotController(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable)
    void ResetCloseTimer();
};
