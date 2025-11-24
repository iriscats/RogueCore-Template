#pragma once
#include "CoreMinimal.h"
#include "AnimationSharing/AnimationSharingStateProcessor.h"
#include "PipelineAnimationSharingProcessor.generated.h"

UCLASS(Blueprintable)
class UPipelineAnimationSharingProcessor : public UAnimationSharingStateProcessor {
    GENERATED_BODY()
public:
    UPipelineAnimationSharingProcessor();
};
