#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "DroppableOutpost.h"
#include "EInputKeys.h"
#include "EPipelineBuildState.h"
#include "ERefineryState.h"
#include "Templates/SubclassOf.h"
#include "FSDRefinery.generated.h"

class APipelineExtractorPod;
class APipelineSegment;
class APipelineStart;
class APlayerCharacter;
class ATrackBuilderItem;
class UDialogDataAsset;
class USingleUsableComponent;
UCLASS(Blueprintable)
class ROGUECORE_API AFSDRefinery : public ADroppableOutpost {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRefineryStateDelegate, ERefineryState, InRefineryState);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRefineryProgressDelegate, float, InProgress01);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRefineryPipelineSegmentDelegate, APipelineSegment*, InSegment);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRefineryPipelineDelegate, APipelineStart*, InPipelineStart);
    DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FRefineryExtractPodDelegate, APipelineExtractorPod*, InExtractorPod);
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRefineryStateDelegate OnRefineryStateChanged;
    FRefineryProgressDelegate OnRefineryProgressChanged;
    FRefineryPipelineDelegate OnPipelineRegistered;
    FRefineryPipelineSegmentDelegate OnPipelineSegmentPlaced;
    FRefineryExtractPodDelegate OnExtractorPodSpawned;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USingleUsableComponent* UsableStartRefining;
    USingleUsableComponent* UsableLaunchRocket;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<float, UDialogDataAsset*> ProgressMissionShouts;
    UDialogDataAsset* LaunchRocketButtonPressedShout;
    TSubclassOf<ATrackBuilderItem> BuilderItem;
    float RefiningTotalDuration;
    FFloatRange PipelineBreakCoolDown;
    float PipelineBreakTimePenaltyPerAdditionalPlayers;
    FInt32Range MaxSegmentBreakDowns;
    int32 SegmentBreakDownPenaltyPerAdditionalPlayers;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_RefineryState, meta=(AllowPrivateAccess=true))
    ERefineryState RefineryState;
    ERefineryState PreviousRefineryState;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    uint8 RefiningProgressReplicated;
    TArray<APipelineStart*> PipelineStarts;
 
    AFSDRefinery(const FObjectInitializer& ObjectInitializer);
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    UFUNCTION(BlueprintCallable)
    void SetRefineryState(ERefineryState InState);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceiveRefineryStateChanged(ERefineryState InState);
    void ReceivePipelineStateChanged(APipelineStart* InPipeline, EPipelineBuildState InState);
    void ReceivePipelineStartReady(APipelineStart* InPipelineStart);
    void OnStartRefiningPressed(APlayerCharacter* InCharacter, EInputKeys Key);
    UFUNCTION()
    void OnRep_RefineryState(ERefineryState InOldState);
    void OnPlayerCharacterRegistered(APlayerCharacter* InCharacter);
    void OnPipelineStateChanged(APipelineStart* InPipelineStart, EPipelineBuildState InPipelineState);
    void OnObjectivesChanged();
    void OnLaunchRocketPressed(APlayerCharacter* InCharacter, EInputKeys Key);
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetRefiningProgress() const;
};
