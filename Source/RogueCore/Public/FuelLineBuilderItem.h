#pragma once
#include "CoreMinimal.h"
#include "TrackBuilderItem.h"
#include "FuelLineBuilderItem.generated.h"

class UItemPlacerAggregator;
UCLASS(Abstract, Blueprintable)
class ROGUECORE_API AFuelLineBuilderItem : public ATrackBuilderItem {
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UItemPlacerAggregator* SegmentPlacer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxRangeToConnection;
    AFuelLineBuilderItem(const FObjectInitializer& ObjectInitializer);
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ReceivePlacementUpdated(bool InCanPlace, bool InConnecting, float InDistanceProgress);
};
