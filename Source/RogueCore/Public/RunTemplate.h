#pragma once
#include "CoreMinimal.h"
#include "ERunDepth.h"
#include "ExpeniteObjective.h"
#include "ObjectiveMissionIcon.h"
#include "PrimaryObjective.h"
#include "ResourceSpawner.h"
#include "SavableDataAsset.h"
#include "SecondaryObjective.h"
#include "Templates/SubclassOf.h"
#include "RunTemplate.generated.h"

class AProceduralSetup;
class UDifficultySetting;
class UMissionDNA;
class UMissionStat;
class UObjective;
class UPrimaryMutator;
class URunStageLayout;
class UStageTemplate;
class UStageTemplateOverride;
UCLASS(Blueprintable)
class URunTemplate : public USavableDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    bool IsUnlockedFromStart;
    UStageTemplate* DefaultStageTemplate;
    TSoftClassPtr<AProceduralSetup> DefaultPLS;
    TArray<TSubclassOf<UMissionDNA>> DefaultDNA;
    TArray<FResourceSpawner> DefaultResourceDistribution;
 
    ERunDepth TutorialDepth;
    TSubclassOf<UMissionDNA> TutorialDNA;
    UPrimaryMutator* TutorialMutator;
    TArray<TSubclassOf<UObjective>> TutorialBannedObjectives;
    FObjectiveMissionIcon IconForDepth1;
    FObjectiveMissionIcon IconForDepth2;
    FObjectiveMissionIcon IconForDepth3;
    FObjectiveMissionIcon IconForDepth4;
    TArray<FPrimaryObjective> PrimaryObjectivesDepth1;
    TArray<FPrimaryObjective> PrimaryObjectivesDepth2;
    TArray<FPrimaryObjective> PrimaryObjectivesDepth3;
    TArray<FPrimaryObjective> PrimaryObjectivesDepth4;
    TArray<FSecondaryObjective> SecondaryObjectivesDepth1;
    TArray<FSecondaryObjective> SecondaryObjectivesDepth2;
    TArray<FSecondaryObjective> SecondaryObjectivesDepth3;
    TArray<FSecondaryObjective> SecondaryObjectivesDepth4;
    TArray<FExpeniteObjective> ExpeniteObjectivesDepth1;
    TArray<FExpeniteObjective> ExpeniteObjectivesDepth2;
    TArray<FExpeniteObjective> ExpeniteObjectivesDepth3;
    TArray<FExpeniteObjective> ExpeniteObjectivesDepth4;
    float HazardBonusDepth1;
    float HazardBonusDepth2;
    float HazardBonusDepth3;
    float HazardBonusDepth4;
    float LevelTimeScaleDepth1;
    float LevelTimeScaleDepth2;
    float LevelTimeScaleDepth3;
    float LevelTimeScaleDepth4;
    UDifficultySetting* BaseDifficultyDepth1;
    UDifficultySetting* BaseDifficultyDepth2;
    UDifficultySetting* BaseDifficultyDepth3;
    UDifficultySetting* BaseDifficultyDepth4;
    URunStageLayout* StageLayoutForDepth1;
    URunStageLayout* StageLayoutForDepth2;
    URunStageLayout* StageLayoutForDepth3;
    URunStageLayout* StageLayoutForDepth4;
    TArray<UStageTemplateOverride*> BossStagesDepth1;
    TArray<UStageTemplateOverride*> BossStagesDepth2;
    TArray<UStageTemplateOverride*> BossStagesDepth3;
    TArray<UStageTemplateOverride*> BossStagesDepth4;
    UMissionStat* CompletedRunStatDepth1;
    UMissionStat* CompletedRunStatDepth2;
    UMissionStat* CompletedRunStatDepth3;
    UMissionStat* CompletedRunStatDepth4;
    URunTemplate();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FSecondaryObjective> GetSecondaryObjectivesForDepth(const ERunDepth Depth) const;
    TArray<FPrimaryObjective> GetPrimaryObjectivesForDepth(const ERunDepth Depth) const;
    float GetLevelTimeScalingForDepth(const ERunDepth Depth) const;
    FObjectiveMissionIcon GetIconForDepth(const ERunDepth Depth) const;
    float GetHazardBonusForDepth(const ERunDepth Depth) const;
    TArray<FExpeniteObjective> GetExpeniteObjectivesForDepth(const ERunDepth Depth) const;
    UMissionStat* GetCompletedRunStatForDepth(const ERunDepth Depth) const;
    UDifficultySetting* GetBaseDifficultyForDepth(const ERunDepth Depth) const;
    TArray<UStageTemplateOverride*> GetAvailableBossesForDepth(const ERunDepth Depth) const;
};
