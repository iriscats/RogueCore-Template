#include "RunMutatorOverrides.h"

FRunMutatorOverrides::FRunMutatorOverrides() {
    this->PrimaryMutatorOverride = ERunItemOverrideType::None;
    this->PrimaryMutator = NULL;
    this->SecondaryMutatorsOverride = ERunListOverrideType::None;
    this->RiskVectorsOverride = ERunListOverrideType::None;
}

