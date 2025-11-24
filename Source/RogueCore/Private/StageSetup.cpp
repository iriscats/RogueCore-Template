#include "StageSetup.h"

FStageSetup::FStageSetup() {
    this->StageSeed = 0;
    this->StageTemplate = NULL;
    this->Biome = NULL;
    this->Type = EStageType::Cave;
    this->Difficulty = NULL;
    this->PrimaryObjective = NULL;
    this->PrimaryMutator = NULL;
    this->StageDNA = NULL;
}

