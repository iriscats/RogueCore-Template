#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTTask_FindPointNearCeiling.generated.h"

UCLASS(Blueprintable)
class UBTTask_FindPointNearCeiling : public UBTTask_BlackboardBase {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CloseToCeilingBias;
    
    float LookForCeilingLength;
    float SearchRadius;
    UBTTask_FindPointNearCeiling();
};
