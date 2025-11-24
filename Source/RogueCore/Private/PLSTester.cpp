#include "PLSTester.h"

APLSTester::APLSTester(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PLSSeed = -1;
    this->missionSeed = -1;
    this->globalSeed = -1;
    this->SpecialEvent = NULL;
    this->RunTemplate = NULL;
    this->RunDepth = ERunDepth::Depth1;
    this->ActiveStage = -1;
    this->Biome = NULL;
    this->PlanetZoneOverride = NULL;
    this->DnaOverride = NULL;
    this->DifficultyOverride = NULL;
    this->BossOverride = NULL;
    this->OverrideDifficulty = NULL;
    this->SimulatePlayerCount = -1;
}


