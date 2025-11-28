#pragma once
#include "CoreMinimal.h"

#include "DroneLightSetting.generated.h"

USTRUCT(BlueprintType)
struct FDroneLightSetting {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor Color = FColor::Black;
    
    float Intensity;
    float Radius;

};
