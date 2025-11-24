#pragma once
#include "CoreMinimal.h"
#include "GenerationComponent.h"
#include "LineSegmentFillerPoint.h"
#include "RandRange.h"
#include "LineSegmentFillerComponent.generated.h"

class UFloodFillSettings;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API ULineSegmentFillerComponent : public UGenerationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLineSegmentFillerPoint> LinePoints;
    
    bool visible;
    UFloodFillSettings* NoiseOverride;
    FRandRange RangeScale;
    FRandRange NoiseRangeScale;
    ULineSegmentFillerComponent(const FObjectInitializer& ObjectInitializer);
};
