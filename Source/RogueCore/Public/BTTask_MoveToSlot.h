#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_MoveToSlot.generated.h"

UCLASS(Blueprintable)
class UBTTask_MoveToSlot : public UBTTask_BlackboardBase {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AcceptableRadius;
    
    float LookAheadTime;
    float VerticalOffset;
    float UpdateRate;
    UBTTask_MoveToSlot();
};
