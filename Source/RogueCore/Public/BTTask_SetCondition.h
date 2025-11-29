#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTTask_SetCondition.generated.h"

UCLASS(Blueprintable)
class UBTTask_SetCondition : public UBTTaskNode {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector ConditionalKey;
    
    bool Value;
    UBTTask_SetCondition();
};
