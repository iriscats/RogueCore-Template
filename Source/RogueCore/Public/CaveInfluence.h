#pragma once
#include "CoreMinimal.h"

#include "CaveInfluence.generated.h"

USTRUCT(BlueprintType)
struct FCaveInfluence {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector Center = FVector::ZeroVector;
    
    float Range;
};
