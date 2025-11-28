#pragma once
#include "CoreMinimal.h"

#include "CellNoise.generated.h"

USTRUCT(BlueprintType)
struct FCellNoise {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Seed;
    
    FVector CellSize;
    int32 NumValues;
    int32 MinCellValue;
    int32 MaxCellValue;
    ROGUECORE_API FCellNoise();
};
