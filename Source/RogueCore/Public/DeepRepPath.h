#pragma once
#include "CoreMinimal.h"

#include "EDeepMovementState.h"
#include "DeepRepPath.generated.h"

USTRUCT(BlueprintType)
struct FDeepRepPath {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector PathBase = FVector::ZeroVector;
    
    uint8 PathLength;
    EDeepMovementState State;
    uint8 StateBits;
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FVector3f PathOffsets[16] = {};

};
