#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_IsOnFloor.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_IsOnFloor : public UBTDecorator {
    GENERATED_BODY()
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AngleLimit;
    
    UBTDecorator_IsOnFloor();
};
