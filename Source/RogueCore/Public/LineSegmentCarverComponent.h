#pragma once
#include "CoreMinimal.h"
#include "GenerationComponent.h"
#include "LineSegmentCarverPoint.h"
#include "LineSegmentCarverComponent.generated.h"

class UFloodFillSettings;
UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ROGUECORE_API ULineSegmentCarverComponent : public UGenerationComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLineSegmentCarverPoint> LinePoints;
    
    bool visible;
    int32 Layer;
    float Cielingheight;
    float FloorDepth;
    UFloodFillSettings* CeilingNoiseOverride;
    UFloodFillSettings* WallNoiseOverride;
    UFloodFillSettings* FloorNoiseOverride;
    bool UseDetailNoise;
    ULineSegmentCarverComponent(const FObjectInitializer& ObjectInitializer);
};
