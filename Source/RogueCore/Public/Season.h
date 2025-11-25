#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveFloat.h"
#include "SavableDataAsset.h"
#include "SeasonLevel.h"
#include "SeasonalEventEntry.h"
#include "SeasonalEventEntryChance.h"
#include "UnassignedReward.h"
#include "WaveEntry.h"
#include "Season.generated.h"

class UGameDLC;
class UMissionStat;
class UReward;
class URewardTree;
class URiskVector;
UCLASS(Blueprintable)
class ROGUECORE_API USeason : public USavableDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText SeasonName;
    
    int32 SeasonNumber;
    TArray<FSeasonLevel> Levels;
    FSeasonLevel RewardAfterAllLevels;
    TArray<FUnassignedReward> UnassignedRewards;
    URewardTree* TreeOfVanity;
    UGameDLC* SeasonDLC;
    FRuntimeFloatCurve SpawnChanceByMissionLength;
    FRuntimeFloatCurve MinorSpawnChanceByMissionLenght;
    TArray<FSeasonalEventEntry> SeasonalEvents;
    TArray<FSeasonalEventEntry> MinorSeasonalEvents;
    TArray<FSeasonalEventEntryChance> SpawnChanceSeasonalEvents;
    int32 NumberOfScripChallenges;
    TArray<UMissionStat*> ScripChallenges;
    TArray<FWaveEntry> SeasonSpecificWaves;
    float SeasonWaveInMissionChance;
    URiskVector* SeasonWarning;
    USeason();
 
    UFUNCTION(BlueprintCallable)
    void AddUnassignedReward(int32 Index, UReward* Reward);
    void AddLevel(int32 Index, UReward* Reward, UReward* specialReward);
};
