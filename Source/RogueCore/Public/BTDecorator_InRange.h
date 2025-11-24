#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_BlackboardBase.h"
#include "UObject/UnrealType.h"
#include "BTDecorator_InRange.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_InRange : public UBTDecorator_BlackboardBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinRange;
    
    float MaxRange;
    FAIDistanceType GeometricDistanceType;
    UBTDecorator_InRange();
};
