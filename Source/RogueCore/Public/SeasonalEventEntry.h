#pragma once
#include "CoreMinimal.h"
#include "SeasonalEventEntry.generated.h"

class UMutator;
class USpecialEvent;
class UStageTemplate;
USTRUCT(BlueprintType)
struct FSeasonalEventEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpecialEvent* SpecialEvent;
    
    TArray<UStageTemplate*> BannedMissions;
    TArray<UMutator*> BannedMutators;
    int32 RequiredMainCampaignProgress;
    ROGUECORE_API FSeasonalEventEntry();
};
