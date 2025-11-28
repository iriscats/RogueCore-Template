#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTService.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTService_UpdateMoveToTarget.generated.h"

UCLASS(Blueprintable)
class UBTService_UpdateMoveToTarget : public UBTService {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TargetKey;
    
    FBlackboardKeySelector TargetLocationKey;
    float LookAheadTime;
    float VerticalOffset;
    UBTService_UpdateMoveToTarget();
};
