#pragma once
#include "CoreMinimal.h"
#include "StateStats.generated.h"

USTRUCT(BlueprintType)
struct FStateStats {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxAcceleration;
    
    float MaxPawnSpeed;
    float MinSlowdownAngle;
    float MaxSlowdownAngle;
    float MaxBreakingDeceleration;
    ROGUECORE_API FStateStats();
};
