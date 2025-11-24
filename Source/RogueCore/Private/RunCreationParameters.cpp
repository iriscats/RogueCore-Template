#include "RunCreationParameters.h"

FRunCreationParameters::FRunCreationParameters() {
    this->RunDepth = ERunDepth::None;
    this->RunTemplate = NULL;
    this->RunSeedOverride = 0;
    this->ActiveStageOverride = 0;
    this->BiomeOverride = NULL;
    this->PlanetZoneOverride = NULL;
    this->DifficultyOverride = NULL;
    this->BossOverride = NULL;
    this->DnaOverride = NULL;
}

