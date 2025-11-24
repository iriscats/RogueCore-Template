#pragma once
#include "CoreMinimal.h"
#include "CoilgunCoil.generated.h"

USTRUCT(BlueprintType)
struct FCoilgunCoil {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Angle;
    
    float Speed;
    ROGUECORE_API FCoilgunCoil();
};
