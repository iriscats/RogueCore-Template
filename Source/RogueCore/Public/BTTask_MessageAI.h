#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_MessageAI.generated.h"

UCLASS(Blueprintable)
class UBTTask_MessageAI : public UBTTaskNode {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MessageName;
    
    UBTTask_MessageAI();
};
