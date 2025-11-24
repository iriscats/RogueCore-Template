#include "PostConstructionSpawnInfo.h"

FPostConstructionSpawnInfo::FPostConstructionSpawnInfo() {
    this->SpawnAmount = 0;
    this->Positioning = NULL;
    this->DistanceCostCurve = NULL;
    this->SpawnChanceMutator = NULL;
    this->MinDistanceToOtherLocations = 0.00f;
    this->MinDistanceToImportantLocations = 0.00f;
    this->OnlySpawnOnFirstStage = false;
    this->UseStaticSpawnPointProbability = 0.00f;
    this->StaticSpawnPointType = EStaticSpawnPointSelectionType::Any;
    this->CanBackfillStaticSpawnPoint = false;
    this->MaxDistanceToCustomActor = 0.00f;
}

