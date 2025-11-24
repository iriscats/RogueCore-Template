#pragma once
#include "CoreMinimal.h"
#include "RandLinePoint.h"
#include "RandRange.h"
#include "RoomFeature.h"
#include "FloodFillPillar.generated.h"

class UFloodFillSettings;
UCLASS(Blueprintable, EditInlineNew)
class UFloodFillPillar : public URoomFeature {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFloodFillSettings* NoiseOverride;

    TArray<FRandLinePoint> Points;

    FRandRange RangeScale;

    FRandRange NoiseRangeScale;

    FRandRange EndcapScale;

public:
    UFloodFillPillar();
};
