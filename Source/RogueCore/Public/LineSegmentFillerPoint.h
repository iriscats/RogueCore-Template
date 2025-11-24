#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RandRange.h"
#include "LineSegmentFillerPoint.generated.h"

USTRUCT(BlueprintType)
struct FLineSegmentFillerPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector position;
    
    FRandRange RandomRange;
    FRandRange RandomNoiseRange;
    FRandRange FillAmount;
    ROGUECORE_API FLineSegmentFillerPoint();
};
