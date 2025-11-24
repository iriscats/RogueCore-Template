#pragma once
#include "CoreMinimal.h"
#include "SeasonalEventEntryChance.generated.h"

class UMutator;
class USpecialEvent;
class UStageTemplate;
USTRUCT(BlueprintType)
struct FSeasonalEventEntryChance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USpecialEvent* SpecialEvent;
    
    float SpawnChance;
    TArray<UStageTemplate*> BannedMissions;
    TArray<UMutator*> BannedMutators;
    ROGUECORE_API FSeasonalEventEntryChance();
};
