#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTask_GravityDrop.generated.h"

UCLASS(Blueprintable)
class ROGUECORE_API UBTTask_GravityDrop : public UBTTaskNode {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InitialDropSpeed;
    
    UBTTask_GravityDrop();
};
