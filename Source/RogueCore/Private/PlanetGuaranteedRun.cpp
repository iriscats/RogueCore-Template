#include "PlanetGuaranteedRun.h"

FPlanetGuaranteedRun::FPlanetGuaranteedRun() {
    this->RunDepth = ERunDepth::None;
    this->Run = NULL;
    this->Biome = NULL;
    this->PlanetZone = NULL;
    this->Duration = NULL;
    this->Complexity = NULL;
    this->DNA = NULL;
    this->Mutator = NULL;
    this->UseRandomMutator = false;
}

