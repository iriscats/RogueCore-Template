#include "RunObjectiveOverrides.h"

FRunObjectiveOverrides::FRunObjectiveOverrides() {
    this->PrimaryObjectiveOverride = ERunItemOverrideType::None;
    this->PrimaryObjective = NULL;
    this->SecondaryObjectivesOverride = ERunListOverrideType::None;
    this->ExpeniteObjectivesOverride = ERunListOverrideType::None;
}

