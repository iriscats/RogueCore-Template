#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_BlackboardBase.h"
#include "UObject/UnrealType.h"
#include "BTDecorator_InRangeEx.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_InRangeEx : public UBTDecorator_BlackboardBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinRange;
    
    float MaxRange;
    FAIDistanceType GeometricDistanceType;
    UBTDecorator_InRangeEx();
};
