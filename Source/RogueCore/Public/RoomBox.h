#pragma once
#include "CoreMinimal.h"

#include "Rotator_NoQuantize.h"
#include "RoomBox.generated.h"

class UFloodFillSettings;
USTRUCT(BlueprintType)
struct FRoomBox {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector position = FVector::ZeroVector;
    
    FRotator_NoQuantize Rotation;
    FVector Extends;
    float NoiseRange;
    UFloodFillSettings* Noise;

};
