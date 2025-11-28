#pragma once
#include "CoreMinimal.h"

#include "Engine/NetSerialization.h"
#include "TentacleTarget.generated.h"

USTRUCT(BlueprintType)
struct FTentacleTarget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector_NetQuantize Location;
    
    FRotator Rotation;
    float MovementDuration;
    bool UseSpring;
    ROGUECORE_API FTentacleTarget();
};
