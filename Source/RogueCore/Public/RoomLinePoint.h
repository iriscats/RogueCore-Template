#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "RoomLinePoint.generated.h"

USTRUCT(BlueprintType)
struct FRoomLinePoint {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector3f Location;
    
    float HRange;
    float VRange;
    float CielingNoiseRange;
    float WallNoiseRange;
    float FloorNoiseRange;
    float Cielingheight;
    float HeightScale;
    float FloorDepth;
    float FloorAngle;
    ROGUECORE_API FRoomLinePoint();
};
