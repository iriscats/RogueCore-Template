#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BlitzMovementState.generated.h"

USTRUCT(BlueprintType)
struct FBlitzMovementState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector TargetPoint;
    
    FVector StoppingPoint;
    bool IsBlitzing;
    ROGUECORE_API FBlitzMovementState();
};
