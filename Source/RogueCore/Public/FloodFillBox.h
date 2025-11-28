#pragma once
#include "CoreMinimal.h"

#include "RoomFeature.h"
#include "FloodFillBox.generated.h"

class UFloodFillSettings;
UCLASS(Blueprintable, EditInlineNew)
class UFloodFillBox : public URoomFeature {
    GENERATED_BODY()

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFloodFillSettings* Noise;

    FVector position;

    FVector Extends;

    FRotator Rotation;

    bool IsCarver;

    float NoiseRange;

public:
    UFloodFillBox();
};
