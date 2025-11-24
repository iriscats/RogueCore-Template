#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "TunnelParameters.generated.h"

class UFloodFillSettings;
UCLASS(Blueprintable)
class UTunnelParameters : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFloodFillSettings* PathfinderNoise;
    
    float PathZStraightnessScale;
    float PathDirectionPenalty;
    float PathEntranceAnglePenalty;
    float ObstacleCostScale;
    bool AllowBlockedEntrances;
    bool PickBestMatchingEntrance;
    bool PickBestMatchingExit;
    bool MatchByDistance;
    UTunnelParameters();
};
