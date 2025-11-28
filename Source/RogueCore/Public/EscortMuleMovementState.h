#pragma once
#include "CoreMinimal.h"

#include "EscortMuleMovementState.generated.h"

USTRUCT(BlueprintType)
struct FEscortMuleMovementState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTransform TargetTransform;
    
    FVector Velocity;
    FQuat AngularVelocity;
    ROGUECORE_API FEscortMuleMovementState();
};
