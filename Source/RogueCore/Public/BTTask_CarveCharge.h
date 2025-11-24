#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "BTTask_CarveCharge.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API UBTTask_CarveCharge : public UBTTaskNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector TargetKey;
    
    float ChargeSpeed;
    float CarveFrequency;
    float CarveRadius;
    float CarveLimit;
    float MaxTurnAnglePerSeconds;
    float OvershootDistance;
    float OvershootCarveLimit;
    float MinTrackingDistance;
    float MaxChargeDistance;
    float AccelerationTime;
    bool IsCarvingEnabled;
    UBTTask_CarveCharge();
};
