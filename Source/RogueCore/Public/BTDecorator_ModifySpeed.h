#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTDecorator_ModifySpeed.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_ModifySpeed : public UBTDecorator {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpeedModifier;
    
    UBTDecorator_ModifySpeed();
};
