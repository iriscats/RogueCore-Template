#pragma once
#include "CoreMinimal.h"

#include "RoomGeneratorItem.generated.h"

class URoomGeneratorBase;
USTRUCT(BlueprintType)
struct FRoomGeneratorItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URoomGeneratorBase* RoomGenerator;
    
    FVector position;
    float Rotation;
    ROGUECORE_API FRoomGeneratorItem();
};
