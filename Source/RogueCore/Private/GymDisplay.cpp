#include "GymDisplay.h"

AGymDisplay::AGymDisplay(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->GymType = EGymDisplayType::TotalSets;
}

EGymDisplayType AGymDisplay::GetGymType() const {
    return EGymDisplayType::TotalSets;
}


