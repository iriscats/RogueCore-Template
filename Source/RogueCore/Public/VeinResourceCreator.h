#pragma once
#include "CoreMinimal.h"
#include "ECarveFilterType.h"
#include "RandRange.h"
#include "ResourceCreator.h"
#include "VeinResourceCreator.generated.h"

class UDebrisBase;
class UDebrisPositioning;
class UFloodFillSettings;
class UVeinResourceData;
UCLASS(Blueprintable, EditInlineNew)
class UVeinResourceCreator : public UResourceCreator {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVeinResourceData* Resource;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* Positioning;
    ECarveFilterType CarveType;
    float SegmentMaxDot;
    float VeinWorldHorizontalMaxDot;
    float VeinWorldHorizontalMinDot;
    FRandRange VeinLength;
    UFloodFillSettings* Noise;
    float Range;
    float NoiseRange;
protected:
    TArray<TSoftObjectPtr<UDebrisBase>> Debris;
    float InfluencerRange;
    UVeinResourceCreator();
};
