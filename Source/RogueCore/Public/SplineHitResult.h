#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"

#include "SplineHitResult.generated.h"

USTRUCT(BlueprintType)
struct FSplineHitResult {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FHitResult HitResult;
    
    float SplineDistance;
    FVector SplineTangent;
    ROGUECORE_API FSplineHitResult();
};
