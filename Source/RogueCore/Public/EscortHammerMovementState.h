#pragma once
#include "CoreMinimal.h"
#include "EscortHammerMovementState.generated.h"

USTRUCT(BlueprintType)
struct FEscortHammerMovementState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Velocity;
    
    float Location;
    float TargetVelocityMultiplier;
    ROGUECORE_API FEscortHammerMovementState();
};
