#pragma once
#include "CoreMinimal.h"
#include "PipelineMovementData.generated.h"

class APipelineSegment;
USTRUCT(BlueprintType)
struct FPipelineMovementData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 Direction;
    
    float Distance;
    float Speed;
    bool UpToSpeed;
    float Acceleration;
    TWeakObjectPtr<APipelineSegment> PipelineSegment;
    ROGUECORE_API FPipelineMovementData();
};
