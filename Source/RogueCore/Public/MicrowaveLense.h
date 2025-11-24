#pragma once
#include "CoreMinimal.h"
#include "MicrowaveLense.generated.h"

USTRUCT(BlueprintType)
struct FMicrowaveLense {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ShotRadiusMultiplier;
    
    float ShotBonusDamageModifier;
    float HeatModifier;
    float RateOfFireModifier;
    ROGUECORE_API FMicrowaveLense();
};
