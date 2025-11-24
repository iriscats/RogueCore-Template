#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Rotator_NoQuantize.h"
#include "Templates/SubclassOf.h"
#include "RoomItem.generated.h"

class AActor;
USTRUCT(BlueprintType)
struct FRoomItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> Spawnable;
    
    FVector Location;
    FRotator_NoQuantize Rotation;
    ROGUECORE_API FRoomItem();
};
