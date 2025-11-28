#pragma once
#include "CoreMinimal.h"

#include "CharacterVanitySave.h"
#include "ItemLoadout.h"
#include "SavedBoosterDecks.h"
#include "UpgradeLoadout.h"
#include "VictoryPoseSave.h"
#include "CharacterSave.generated.h"

USTRUCT(BlueprintType)
struct FCharacterSave {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGuid SavegameID;

    int32 XP;
    bool HasCompletedRetirementCampaign;
    int32 TimesRetired;
    int32 RetiredCharacterLevels;
    bool HasSeenRetirementRewardScreen;
    FCharacterVanitySave Vanity;
    int32 SelectedLoadout;
    FItemLoadout Loadout;
    TArray<FItemLoadout> Loadouts;
    TArray<FUpgradeLoadout> ItemUpgradeLoadouts;
    FItemLoadout RandomWeaponLoadout;
    FUpgradeLoadout RandomItemUpgradeLoadouts;
    FVictoryPoseSave VictoryPose;
    FSavedBoosterDecks BoosterDecks;
    ROGUECORE_API FCharacterSave();
};
