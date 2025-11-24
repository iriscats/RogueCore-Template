#pragma once
#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_BlackboardBase.h"
#include "BehaviorTree/BehaviorTreeTypes.h"
#include "UObject/UnrealType.h"
#include "BTDecorator_InRangeBB.generated.h"

UCLASS(Blueprintable)
class UBTDecorator_InRangeBB : public UBTDecorator_BlackboardBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlackboardKeySelector MinRangeKey;
    
    FBlackboardKeySelector MaxRangeKey;
    FAIDistanceType GeometricDistanceType;
    UBTDecorator_InRangeBB();
};
