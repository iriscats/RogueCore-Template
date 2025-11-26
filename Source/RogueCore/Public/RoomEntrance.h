#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ECaveEntrancePriority.h"
#include "ECaveEntranceType.h"
#include "RoomEntrance.generated.h"

USTRUCT(BlueprintType)
struct FRoomEntrance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector3f Location = FVector3f::ZeroVector;
    
    FVector3f Direction;
    bool IsBlocked;
    ECaveEntranceType EntranceType;
    ECaveEntrancePriority Priority;
    int32 PathObstacleID;

};
