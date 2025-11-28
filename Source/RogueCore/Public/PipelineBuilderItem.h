#pragma once
#include "CoreMinimal.h"
#include "TrackBuilderItem.h"
#include "PipelineBuilderItem.generated.h"

class UItemPlacerAggregator;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API APipelineBuilderItem : public ATrackBuilderItem {
    GENERATED_BODY()
    

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemPlacerAggregator* SegmentPlacer;
    
    APipelineBuilderItem(const FObjectInitializer& ObjectInitializer);
};
