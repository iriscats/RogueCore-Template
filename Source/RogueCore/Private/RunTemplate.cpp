#include "RunTemplate.h"

URunTemplate::URunTemplate() {
    this->IsUnlockedFromStart = false;
    this->DefaultStageTemplate = NULL;
    this->TutorialDepth = ERunDepth::None;
    this->TutorialDNA = NULL;
    this->TutorialMutator = NULL;
    this->HazardBonusDepth1 = 1.00f;
    this->HazardBonusDepth2 = 1.00f;
    this->HazardBonusDepth3 = 1.00f;
    this->HazardBonusDepth4 = 1.00f;
    this->LevelTimeScaleDepth1 = 1.00f;
    this->LevelTimeScaleDepth2 = 1.00f;
    this->LevelTimeScaleDepth3 = 1.00f;
    this->LevelTimeScaleDepth4 = 1.00f;
    this->BaseDifficultyDepth1 = NULL;
    this->BaseDifficultyDepth2 = NULL;
    this->BaseDifficultyDepth3 = NULL;
    this->BaseDifficultyDepth4 = NULL;
    this->StageLayoutForDepth1 = NULL;
    this->StageLayoutForDepth2 = NULL;
    this->StageLayoutForDepth3 = NULL;
    this->StageLayoutForDepth4 = NULL;
    this->CompletedRunStatDepth1 = NULL;
    this->CompletedRunStatDepth2 = NULL;
    this->CompletedRunStatDepth3 = NULL;
    this->CompletedRunStatDepth4 = NULL;
}

TArray<FSecondaryObjective> URunTemplate::GetSecondaryObjectivesForDepth(const ERunDepth Depth) const {
    return TArray<FSecondaryObjective>();
}

TArray<FPrimaryObjective> URunTemplate::GetPrimaryObjectivesForDepth(const ERunDepth Depth) const {
    return TArray<FPrimaryObjective>();
}

float URunTemplate::GetLevelTimeScalingForDepth(const ERunDepth Depth) const {
    return 0.0f;
}

FObjectiveMissionIcon URunTemplate::GetIconForDepth(const ERunDepth Depth) const {
    return FObjectiveMissionIcon{};
}

float URunTemplate::GetHazardBonusForDepth(const ERunDepth Depth) const {
    return 0.0f;
}

TArray<FExpeniteObjective> URunTemplate::GetExpeniteObjectivesForDepth(const ERunDepth Depth) const {
    return TArray<FExpeniteObjective>();
}

UMissionStat* URunTemplate::GetCompletedRunStatForDepth(const ERunDepth Depth) const {
    return NULL;
}

UDifficultySetting* URunTemplate::GetBaseDifficultyForDepth(const ERunDepth Depth) const {
    return NULL;
}

TArray<UStageTemplateOverride*> URunTemplate::GetAvailableBossesForDepth(const ERunDepth Depth) const {
    return TArray<UStageTemplateOverride*>();
}


