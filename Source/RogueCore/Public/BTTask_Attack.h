#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTTask_Attack.generated.h"

class UBehaviorTreeComponent;
UCLASS(Blueprintable)
class UBTTask_Attack : public UBTTaskNode {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TargetKey;
    
    FName AttackName;
    UBTTask_Attack();
protected:
    UFUNCTION(BlueprintCallable)
    void OnAttackCompleted(UBehaviorTreeComponent* btComponent, const bool& wasSuccess);
};
