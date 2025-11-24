#pragma once
#include "CoreMinimal.h"
#include "CarveSplineSegment.h"
#include "ECarveFilterType.h"
#include "EPreciousMaterialOptions.h"
#include "SplineSegmentCarveOperationData.generated.h"

class UTerrainMaterial;
USTRUCT(BlueprintType)
struct FSplineSegmentCarveOperationData {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 OperationNumber;
    
    TArray<FCarveSplineSegment> Segments;
    UTerrainMaterial* Material;
    ECarveFilterType CarveFilter;
    EPreciousMaterialOptions Precious;
    float Noise;
    ROGUECORE_API FSplineSegmentCarveOperationData();
};
