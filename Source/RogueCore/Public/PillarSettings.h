#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "PillarSegment.h"
#include "RandRange.h"
#include "PillarSettings.generated.h"

class UFloodFillSettings;
UCLASS(Blueprintable)
class UPillarSettings : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FPillarSegment> PillarSegments;
    
    FRandRange PointRange;
    FRandRange PointNoiseRange;
    FRandRange PillarRangeScale;
    FRandRange PillarNoiseRangeScale;
    UFloodFillSettings* Noise;
    UPillarSettings();
};
