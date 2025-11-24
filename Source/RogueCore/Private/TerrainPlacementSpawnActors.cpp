#include "TerrainPlacementSpawnActors.h"

FTerrainPlacementSpawnActors::FTerrainPlacementSpawnActors() {
    this->SpawnActorClass = NULL;
    this->SpawnPositioning = NULL;
    this->AmountToSpawn = 0;
    this->AmountToSpawnMinimum = 0;
    this->NumberOfAllowedChecks = 0;
    this->MinimumDistanceBetweenSpawns = 0.00f;
    this->AddTerrainPlacementBlockers = false;
}

