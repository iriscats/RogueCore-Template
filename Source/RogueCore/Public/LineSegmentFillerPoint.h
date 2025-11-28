#pragma once
#include "CoreMinimal.h"

#include "RandRange.h"
#include "LineSegmentFillerPoint.generated.h"

USTRUCT(BlueprintType)
struct FLineSegmentFillerPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector position = FVector::ZeroVector;
    
    FRandRange RandomRange;
    FRandRange RandomNoiseRange;
    FRandRange FillAmount;

};
