#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RandRange.h"
#include "RandLinePoint.generated.h"

USTRUCT(BlueprintType)
struct FRandLinePoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector3f Location = FVector3f::ZeroVector;
    
    FRandRange Range;
    FRandRange NoiseRange;
    FRandRange SkewFactor;
    FRandRange FillAmount;

};
