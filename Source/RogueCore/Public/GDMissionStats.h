#pragma once
#include "CoreMinimal.h"
#include "GDMissionStats.generated.h"

class UMissionStat;
class UPlayerCharacterID;
USTRUCT(BlueprintType)
struct FGDMissionStats {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMissionStat* TimePlayed;
    
    UMissionStat* DistanceTravelled;
    UMissionStat* EnemiesKilled;
    UMissionStat* MineralsMined;
    UMissionStat* MissionCompleted;
    UMissionStat* SoloMissionCompleted;
    UMissionStat* SecondaryMissionCompleted;
    UMissionStat* CharacterLevelUp;
    UMissionStat* VanityItemsBought;
    UMissionStat* ItemUpgradesBought;
    UMissionStat* CosmeticMasteryLevelledUp;
    UMissionStat* DrinkablesConsumed;
    UMissionStat* DrinkableRoundsOrdered;
    UMissionStat* BartenderCreditsTipped;
    UMissionStat* CampaignMissionsCompleted;
    UMissionStat* CampaignsCompleted;
    UMissionStat* TimesDowned;
    UMissionStat* TimesPassedOut;
    UMissionStat* WeaponsUnlockedStat;
    UMissionStat* SeasonEventsCompleted;
    UMissionStat* SeasonChallengesCompleted;
    UMissionStat* DeepDivesCompleted;
    UMissionStat* EliteDeepDivesCompleted;
    UMissionStat* CosmeticsCrafted;
    UMissionStat* WeaponSkinsCrafted;
    UMissionStat* WeaponOverclocksCrafted;
    UMissionStat* CraftingMasteryLevel;
    UMissionStat* DefendBlackBoxObjectivesCompleted;
    UMissionStat* RepairMiniMuleObjectivesCompleted;
    UMissionStat* DeepDiveCompletedBestTime;
    UMissionStat* EliteDeepDiveCompletedBestTime;
    UMissionStat* SpecialBeersUnlocked;
    UMissionStat* JettyBootCreditsSpent;
    TArray<UMissionStat*> AllMissionStats;
    ROGUECORE_API FGDMissionStats();
protected:
    TMap<UPlayerCharacterID*, UMissionStat*> CharacterMissionsCompleted;
};
