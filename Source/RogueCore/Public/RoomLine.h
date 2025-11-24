#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RoomLinePoint.h"
#include "RoomLine.generated.h"

class UFloodFillSettings;
USTRUCT(BlueprintType)
struct FRoomLine {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFloodFillSettings* WallNoiseOverride;
    
    UFloodFillSettings* CeilingNoiseOverride;
    UFloodFillSettings* FloorNoiseOverride;
    bool UseDetailNoise;
    TArray<FRoomLinePoint> Points;
    TArray<FVector3f> RightVectors;
    ROGUECORE_API FRoomLine();
};
