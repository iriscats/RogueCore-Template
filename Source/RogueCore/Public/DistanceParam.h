#pragma once
#include "CoreMinimal.h"

#include "DistanceParam.generated.h"

USTRUCT(BlueprintType)
struct FDistanceParam {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Location = FVector::ZeroVector;
    
    float MinDistance;
    float MaxDistance;

};
