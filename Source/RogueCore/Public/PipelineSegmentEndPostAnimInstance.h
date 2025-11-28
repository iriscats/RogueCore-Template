#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "PipelineSegmentEndPostAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class UPipelineSegmentEndPostAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AssemblyAnimLength;
    
    float AssemblyTimeTarget;
    float AssemblyTime;
    bool bAssembling;
    UPipelineSegmentEndPostAnimInstance();
};
