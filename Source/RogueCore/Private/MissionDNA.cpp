#include "MissionDNA.h"

UMissionDNA::UMissionDNA() {
    this->MissionScale = 100.00f;
    this->Weight = 1.00f;
    this->AmountOfStages = 3;
    this->XpPerStage = 200;
    this->XpPerStageNumberMultiplier = 0.50f;
    this->ExtraStageTime = 0.00f;
    this->Complexity = NULL;
    this->Duration = NULL;
}

float UMissionDNA::GetDurationHazardBonus() const {
    return 0.0f;
}

float UMissionDNA::GetComplexityHazardBonus() const {
    return 0.0f;
}


