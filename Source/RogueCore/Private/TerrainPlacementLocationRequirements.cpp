#include "TerrainPlacementLocationRequirements.h"

FTerrainPlacementLocationRequirements::FTerrainPlacementLocationRequirements() {
    this->DistanceCostCurve = NULL;
    this->AvoidImportantLocations = false;
    this->MinimumDistanceToImportantLocation = 0.00f;
}

