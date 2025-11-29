#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTTask_FaceTarget.generated.h"

UCLASS(Blueprintable)
class UBTTask_FaceTarget : public UBTTaskNode {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TargetKey;
    
    float MinAngle;
    UBTTask_FaceTarget();
};
