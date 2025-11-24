#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TunnelSettingItem.h"
#include "TunnelSetting.generated.h"

class UFloodFillSettings;
class UTunnelSegmentSetting;
UCLASS(Blueprintable)
class UTunnelSetting : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFloodFillSettings* PathfinderNoise;
    
    UTunnelSegmentSetting* BaseSegmentSetting;
    UTunnelSegmentSetting* TightBendSegmentSetting;
    UTunnelSegmentSetting* DirtSegmentSetting;
    UTunnelSegmentSetting* DirtOffsetSetting;
    TArray<FTunnelSettingItem> VariationSegments;
    float Weight;
    UTunnelSetting();
};
