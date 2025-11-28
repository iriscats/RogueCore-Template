#pragma once
#include "CoreMinimal.h"

#include "SplineSegment.generated.h"

USTRUCT(BlueprintType)
struct FSplineSegment {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector StartLocation = FVector::ZeroVector;
    
    FVector StartTangent;
    FVector EndLocation;
    FVector EndTangent;

};
