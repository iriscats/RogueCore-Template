#pragma once
#include "CoreMinimal.h"
#include "DeadPlayerPlacementSettings.generated.h"

class UDebrisPositioning;
USTRUCT(BlueprintType)
struct FDeadPlayerPlacementSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDebrisPositioning* FallbackPositioning;
    
    int32 FallbackPlaceInRoomIndex;
    ROGUECORE_API FDeadPlayerPlacementSettings();
};
