#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "LineSegmentCarverPoint.generated.h"

USTRUCT(BlueprintType)
struct FLineSegmentCarverPoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector position = FVector::ZeroVector;
    
    float HRange;
    float VRange;
    float FloorAngle;
    float CielingNoiseRange;
    float WallNoiseRange;
    float FloorNoiseRange;

};
