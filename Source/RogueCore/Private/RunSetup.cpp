#include "RunSetup.h"

FRunSetup::FRunSetup() {
    this->RunSeed = 0;
    this->RunDepth = ERunDepth::None;
    this->RunTemplate = NULL;
    this->RunDNA = NULL;
    this->RunMutator = NULL;
    this->PlanetZone = NULL;
}

