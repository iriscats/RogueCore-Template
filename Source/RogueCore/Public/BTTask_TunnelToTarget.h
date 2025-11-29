#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeTypes.h"

#include "BTTask_TunnelToTarget.generated.h"

UCLASS(Blueprintable)
class UBTTask_TunnelToTarget : public UBTTaskNode {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TargetKey;
    
    float BurrowSpeed;
    float BurrowDuration;
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FFloatInterval DurationClamp;
    UBTTask_TunnelToTarget();
};
