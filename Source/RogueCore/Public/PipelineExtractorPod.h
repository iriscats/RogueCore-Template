#pragma once
#include "CoreMinimal.h"
#include "RessuplyPod.h"
#include "PipelineExtractorPod.generated.h"

class APipelineSegment;
class APlayerCharacter;
UCLASS(Abstract, Blueprintable, NoExport)
class ROGUECORE_API APipelineExtractorPod : public ARessuplyPod {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ConnectedSegment, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<APipelineSegment> ConnectedSegment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float TargetRotation;
    APipelineExtractorPod(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void SetTargetRotation(APipelineSegment* InPipelineSegment);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveConnectedToSegment(APipelineSegment* InConnectedSegment);
    UFUNCTION(BlueprintCallable)
    void OnRep_ConnectedSegment();
    void ExtractorPodOrderedEvent(APlayerCharacter* InUser);
};
