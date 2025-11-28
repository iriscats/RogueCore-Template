#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_TriggerAI.generated.h"

UCLASS(Blueprintable)
class UBTTask_TriggerAI : public UBTTaskNode {
    GENERATED_BODY()
    

public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TriggerName;
    
    UBTTask_TriggerAI();
};
