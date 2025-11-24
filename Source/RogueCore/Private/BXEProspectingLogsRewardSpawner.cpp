#include "BXEProspectingLogsRewardSpawner.h"

ABXEProspectingLogsRewardSpawner::ABXEProspectingLogsRewardSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->terrainPlacement = NULL;
    this->DebrisPositioning = NULL;
    this->CostCurve = NULL;
    this->DebrisPartsToSpawn = 1;
    this->MaxSpawnLocationTries = 10;
    this->RewardInstance = NULL;
    this->Objective = NULL;
}

void ABXEProspectingLogsRewardSpawner::SpawnRewardInstance() {
}


