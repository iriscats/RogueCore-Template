#include "StageSeedParameters.h"

FStageSeedParameters::FStageSeedParameters() {
    this->ActiveSeed = 0;
    this->ActiveDepth = ERunDepth::None;
    this->ActiveRun = NULL;
    this->ActiveBiome = NULL;
    this->ActiveDNA = NULL;
    this->ActiveStage = 0;
    this->ActiveMutator = NULL;
}

