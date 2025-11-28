#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "EPipelineBuildState.h"
#include "EPipelineExtractorPodAnimState.h"
#include "ERefineryState.h"
#include "ERessuplyPodState.h"
#include "PipelineExtractorPodAnimInstance.generated.h"

class AFSDRefinery;
class APipelineExtractorPod;
class APipelineSegment;
class APipelineStart;
UCLASS(Abstract, Blueprintable, NonTransient)
class ROGUECORE_API UPipelineExtractorPodAnimInstance : public UAnimInstance {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ConnectionRotation;
    
    EPipelineExtractorPodAnimState AnimState;
    ERessuplyPodState PodState;
    EPipelineBuildState PipelineState;
    ERefineryState RefineryState;
    float RotationSpeed;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APipelineExtractorPod> Pod;
    TWeakObjectPtr<APipelineSegment> ConnectedSegment;
    TWeakObjectPtr<APipelineStart> PipelineStart;
    TWeakObjectPtr<AFSDRefinery> Refinery;
    UPipelineExtractorPodAnimInstance();
};
