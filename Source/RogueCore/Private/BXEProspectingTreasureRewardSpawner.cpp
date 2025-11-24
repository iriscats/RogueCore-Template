#include "BXEProspectingTreasureRewardSpawner.h"

ABXEProspectingTreasureRewardSpawner::ABXEProspectingTreasureRewardSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->terrainPlacement = NULL;
    this->RewardClass = NULL;
    this->DebrisPositioning = NULL;
    this->CostCurve = NULL;
    this->DebrisPartsToSpawn = 1;
    this->MaxSpawnLocationTries = 10;
    this->RewardInstance = NULL;
    this->Objective = NULL;
}

void ABXEProspectingTreasureRewardSpawner::SpawnRewardInstance() {
}


