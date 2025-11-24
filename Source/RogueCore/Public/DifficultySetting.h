#pragma once
#include "CoreMinimal.h"
#include "IRandRange.h"
#include "RandInterval.h"
#include "SavableDataAsset.h"
#include "Templates/SubclassOf.h"
#include "VeteranComposition.h"
#include "DifficultySetting.generated.h"

class UCampaign;
class UMissionStat;
class UObject;
UCLASS(Blueprintable)
class ROGUECORE_API UDifficultySetting : public USavableDataAsset {
    GENERATED_BODY()
    // UPROPERTY fields moved from protected section
public:

    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText DifficultyName;
    
    FText ShortDifficultyName;
    FText UnlockRequirementDescription;
    TSubclassOf<UCampaign> CampaignRequirement;
    TSubclassOf<UCampaign> SelectedByDefaultCampaignRequirement;
    float EnvironmentalDamageModifier;
    UPROPERTY(BlueprintReadWrite, EditAnywhere, EditFixedSize, meta=(AllowPrivateAccess=true))
    TArray<float> ExtraLargeEnemyDamageResistance;
    TArray<float> ExtraLargeEnemyDamageResistanceB;
    TArray<float> ExtraLargeEnemyDamageResistanceC;
    TArray<float> ExtraLargeEnemyDamageResistanceD;
    TArray<float> EnemyDamageResistance;
    TArray<float> SmallEnemyDamageResistance;
    TArray<float> EnemyDamageModifier;
    float EnemyToEnemyDamageModifier;
    TArray<float> EnemyCountModifier;
    float BossDifficultyScaler;
    float PointExtractionScaler;
    FRandInterval EncounterDifficulty;
    FRandInterval StationaryDifficulty;
    float SpecialEncounterModifier;
    float FriendlyFireModifier;
    FRandInterval EnemyWaveInterval;
    FRandInterval EnemyNormalWaveInterval;
    FRandInterval EnemyNormalWaveDifficulty;
    float WaveStartDelayScale;
    FRandInterval EnemyDiversity;
    FRandInterval StationaryEnemyDiversity;
    FIRandRange DisruptiveEnemyPoolCount;
    int32 MinPoolSize;
    FVeteranComposition Veterans;
    float SpeedModifier;
    float AttackCooldownModifier;
    float ProjectileSpeedModifier;
    int32 DifficultyGroup;
    int32 DifficultyGroupIndex;
    TArray<UMissionStat*> MissionCompletedStats;
    float HeathRegenerationMax;
    float ReviveHealthRatio;
    UDifficultySetting();
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContext"))
    bool IsUnlocked(UObject* WorldContext) const;
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetDifficultyIndex() const;
};
