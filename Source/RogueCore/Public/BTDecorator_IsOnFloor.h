#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_IsOnFloor.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_IsOnFloor : public UBTDecorator {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AngleLimit;
    
    UBTDecorator_IsOnFloor();
};
