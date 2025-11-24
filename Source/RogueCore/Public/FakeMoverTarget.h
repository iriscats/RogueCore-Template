#pragma once
#include "CoreMinimal.h"
#include "FakeMoverTarget.generated.h"

USTRUCT(BlueprintType)
struct FFakeMoverTarget {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InfluenceDistance;
    
    float TargetDistance;
    float GetCloserAirAcceleration;
    float GetAwayAirAcceleration;
    float GetCloserGroundAcceleration;
    float GetAwayGroundAcceleration;
    float MinDistance;
    ROGUECORE_API FFakeMoverTarget();
};
