#pragma once
#include "CoreMinimal.h"
#include "FakeMoverPropulsion.generated.h"

USTRUCT(BlueprintType)
struct FFakeMoverPropulsion {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Speed;
    
    float AirAcceleration;
    float AirDeceleration;
    float GroundAcceleration;
    float GroundDeceleration;
    ROGUECORE_API FFakeMoverPropulsion();
};
