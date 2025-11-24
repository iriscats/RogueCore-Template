#include "BXEPLSTester.h"

ABXEPLSTester::ABXEPLSTester(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Seed = -1;
    this->SimulatePlayerCount = -1;
    this->RunDepth = ERunDepth::Depth1;
    this->RunTemplate = NULL;
    this->ActiveStage = -1;
    this->Biome = NULL;
    this->PlanetZoneOverride = NULL;
    this->DifficultyOverride = NULL;
    this->BossOverride = NULL;
    this->DnaOverride = NULL;
}


