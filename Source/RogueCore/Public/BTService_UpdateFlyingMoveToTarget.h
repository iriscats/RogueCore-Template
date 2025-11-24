#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTService_UpdateFlyingMoveToTarget.generated.h"

UCLASS(Blueprintable)
class UBTService_UpdateFlyingMoveToTarget : public UBTService {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section


public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TargetKey;
    
    FBlackboardKeySelector TargetLocationKey;
    float LookAheadTime;
    UBTService_UpdateFlyingMoveToTarget();
};
