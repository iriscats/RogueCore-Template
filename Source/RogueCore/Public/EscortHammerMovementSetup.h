#pragma once
#include "CoreMinimal.h"
#include "EscortHammerMovementSetup.generated.h"

USTRUCT(BlueprintType)
struct FEscortHammerMovementSetup {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetLocationPerc;
    
    float TargetVelocity;
    float Acceleration;
    bool PathfinderCollisionEnabled;
    ROGUECORE_API FEscortHammerMovementSetup();
};
