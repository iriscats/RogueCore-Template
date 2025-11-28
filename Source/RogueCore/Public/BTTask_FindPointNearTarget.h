#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeTypes.h"

#include "BTTask_FindPointNearTarget.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API UBTTask_FindPointNearTarget : public UBTTaskNode {
    GENERATED_BODY()
    // UPROPERTY fields moved from private section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TargetKey;
    
    FBlackboardKeySelector LocationKey;
    float Distance;
    FVector ManualOffset;
    bool FromCenterOfMass;
    UBTTask_FindPointNearTarget();
};
