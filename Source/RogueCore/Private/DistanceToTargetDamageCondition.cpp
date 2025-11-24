#include "DistanceToTargetDamageCondition.h"

UDistanceToTargetDamageCondition::UDistanceToTargetDamageCondition() {
    this->MinimumDistance = 0.00f;
    this->MaxDistance = 99999.00f;
    this->Mode = EDamageConditionDistanceMode::FromInstigator;
}


