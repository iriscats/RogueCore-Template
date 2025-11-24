#pragma once
#include "CoreMinimal.h"
#include "RoomFeature.h"
#include "RoomLinePoint.h"
#include "FloodFillLine.generated.h"

class UFloodFillSettings;
UCLASS(Blueprintable, EditInlineNew)
class UFloodFillLine : public URoomFeature {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFloodFillSettings* WallNoiseOverride;

    UFloodFillSettings* CeilingNoiseOverride;

    UFloodFillSettings* FloorNoiseOverride;

    bool UseDetailNoise;

    TArray<FRoomLinePoint> Points;

public:
    UFloodFillLine();
};
