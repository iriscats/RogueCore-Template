#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "EInputKeys.h"
#include "ERessuplyPodState.h"
#include "Templates/SubclassOf.h"
#include "PipelineFinish.generated.h"

class APipelineExtractorPod;
class APipelineSegment;
class APlayerCharacter;
class ARessuplyPod;
class ATrackBuilderSegment;
class USingleUsableComponent;
class UTrackBuilderConnectPoint;
UCLASS(Abstract, Blueprintable, NoExport)
class ROGUECORE_API APipelineFinish : public AActor {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section

public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTrackBuilderConnectPoint* PipelineEndConnection;
    
    USingleUsableComponent* UsableOrderExtractor;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<APipelineExtractorPod> ExtractPodClass;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_ExtractorPod, meta=(AllowPrivateAccess=true))
    APipelineExtractorPod* ExtractorPod;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_PipelineCompleted, meta=(AllowPrivateAccess=true))
    bool bPipelineCompleted;
    APipelineFinish(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceivePipelineCompleted();
    void ReceiveExtractorPodSpawned(APipelineExtractorPod* InExtractorPod);
    UFUNCTION(BlueprintCallable)
    void OnRep_PipelineCompleted();
    UFUNCTION()
    void OnRep_ExtractorPod();
    void OnExtractorPodStateChanged(ARessuplyPod* InExtractorPod, ERessuplyPodState InState);
    void OnExtractorPodOrdered(APlayerCharacter* InUser, EInputKeys Key);
    void OnConnectedWithSegment(UTrackBuilderConnectPoint* InConnectPoint, ATrackBuilderSegment* InSegment);
    void OnConnectedSegmentActivated(APipelineSegment* InSegment);
    FVector GetLandingOffset();
};
