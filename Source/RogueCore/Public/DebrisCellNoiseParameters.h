#pragma once
#include "CoreMinimal.h"
#include "DebrisCellNoiseParameters.generated.h"

class UDebrisCellNoise;
USTRUCT(BlueprintType)
struct FDebrisCellNoiseParameters {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDebrisCellNoise* Noise;
    
    int32 MinCellValue;
    int32 MaxCellValue;
    ROGUECORE_API FDebrisCellNoiseParameters();
};
