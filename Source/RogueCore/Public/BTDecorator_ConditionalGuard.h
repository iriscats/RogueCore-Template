#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTDecorator_ConditionalGuard.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_ConditionalGuard : public UBTDecorator {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector GuardKey;
    
    bool InvertLogic;
    UBTDecorator_ConditionalGuard();
};
