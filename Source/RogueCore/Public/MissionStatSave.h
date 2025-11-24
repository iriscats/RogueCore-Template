#pragma once
#include "CoreMinimal.h"
#include "MissionStatCounter.h"
#include "MissionStatSave.generated.h"

USTRUCT(BlueprintType)
struct FMissionStatSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMissionStatCounter> Counters;

    bool bCharacterLevelUpFixed;
    bool bBoughtVanityItemsFixed;
    bool bBoughtEquipmentUpgradesFixed;
    bool bCampaignsCompletedFixed;
    bool WeaponUpgradesFixed;
    ROGUECORE_API FMissionStatSave();
protected:
};
