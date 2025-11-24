#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AchievementList.generated.h"

class AActor;
class UFSDAchievement;
UCLASS(Blueprintable)
class UAchievementList : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFSDAchievement* WeakspotAchievement;
    
    UFSDAchievement* MissionTimeAchievement;
    UFSDAchievement* MissionHosterAchievement;
    UFSDAchievement* RollerCoasterAchievement;
    UFSDAchievement* DrillByShootingAchievement;
    UFSDAchievement* BarrelKickerAchievement;
    UFSDAchievement* Hazard3CompletedAchievement;
    UFSDAchievement* Hazard3StreakAchievement;
    UFSDAchievement* Hazard4CompletedAchievement;
    UFSDAchievement* Hazard4StreakAchievement;
    UFSDAchievement* Hazard5CompletedAchievement;
    UFSDAchievement* Hazard5StreakAchievement;
    UFSDAchievement* Hazard3NoKillNoSupplyAchievement;
    UFSDAchievement* Hazard4NoKillNoSupplyAchievement;
    UFSDAchievement* Hazard5NoKillNoSupplyAchievement;
    UFSDAchievement* PlayedWithLowerRankAchievement;
    UFSDAchievement* MilestoneAchievementPerfMatters;
    UFSDAchievement* MilestoneAchievement;
    UFSDAchievement* OwnedPerkAchievement;
    UFSDAchievement* MovingOnUpAchievement;
    UFSDAchievement* CorporateClimberAchievement;
    UFSDAchievement* HatTrickAchievement;
    UFSDAchievement* FullTeamAchievement;
    UFSDAchievement* SilverTierEmployeeAchievement;
    UFSDAchievement* ProTeamAchievement;
    UFSDAchievement* GoldTierEmployeeAchievement;
    UFSDAchievement* LegendaryTeamAchievement;
    UFSDAchievement* AllVanityEquippedAchievement;
    UFSDAchievement* MoustacheBuyerAchievement;
    UFSDAchievement* MutatorAchievement;
    UFSDAchievement* StateOfTheArtAchievement;
    UFSDAchievement* ExploringMyOptionsAchievement;
    UFSDAchievement* AdvancedRoboticsAchievement;
    UFSDAchievement* WithoutAPaddleAchievement;
    UFSDAchievement* FirstMissionCompleted;
    UFSDAchievement* HundredMissionsCompleted;
    UFSDAchievement* TenSoloMissionsCompleted;
    UFSDAchievement* SupplyPodsCalledStat;
    UFSDAchievement* LootbugsKilledStat;
    UFSDAchievement* PraetoriansKilledStat;
    UFSDAchievement* NormalDeepDiveCompleted;
    UFSDAchievement* EliteDeepDiveCompleted;
    UFSDAchievement* DeepDiveCompletedUnderTime;
    UFSDAchievement* DeepDivesCompleted;
    TArray<UFSDAchievement*> AllAchievements;
    TSoftClassPtr<AActor> BarrelClass;
    UAchievementList();
};
