#include "BXESettings.h"

UBXESettings::UBXESettings() {
    this->ProgressionSettings = NULL;
    this->MissionStats = NULL;
    this->BXETreasureSettings = NULL;
    this->RunSettings = NULL;
    this->RewardTree = NULL;
    this->BXENameBank = NULL;
    this->ObjectivesAreRequired = true;
    this->CreditsPerPrimaryObjective = 1000;
    this->CreditsPerSecondaryObjective = 1000;
    this->XPPerPrimaryObjective = 1000;
    this->XPPerExpenite = 2;
    this->XPNiteValueMultiplier = 1.00f;
    this->XPPerKill = 10.00f;
    this->MaxReclaimerPointLevel = 100;
    this->XPToReclaimerPointsConversionRate = 1.50f;
    this->XPToReclaimerPointsCurve = NULL;
    this->ReclaimerPointsToChipConversionRate = 6000.00f;
    this->SecurityCameraReclaimerPointsMultiplier = 0.10f;
    this->DeepCoreBiome = NULL;
}


