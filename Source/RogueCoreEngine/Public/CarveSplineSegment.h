#pragma once
#include "CoreMinimal.h"

#include "CarveSplineSegment.generated.h"

USTRUCT(BlueprintType)
struct ROGUECOREENGINE_API FCarveSplineSegment {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector3f SplineStart = FVector3f::ZeroVector;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector3f SplineStartTangent = FVector3f::ZeroVector;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector3f SplineEnd = FVector3f::ZeroVector;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    FVector3f SplineEndTangent = FVector3f::ZeroVector;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (AllowPrivateAccess = true))
    float Radius = 0.0f;

    FCarveSplineSegment() = default;
};
