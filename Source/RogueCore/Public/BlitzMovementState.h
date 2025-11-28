#pragma once
#include "CoreMinimal.h"

#include "BlitzMovementState.generated.h"

USTRUCT(BlueprintType)
struct FBlitzMovementState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TargetPoint = FVector::ZeroVector;
    
    FVector StoppingPoint;
    bool IsBlitzing;

};
