#include "PlaceActorParams.h"

FPlaceActorParams::FPlaceActorParams() {
    this->NumToSpawn = 0;
    this->NumToSpawnMin = 0;
    this->NumAllowedChecks = 0;
    this->SpawnedActorClass = NULL;
    this->setup = NULL;
    this->DebrisPositioning = NULL;
    this->AvoidCostCurve = NULL;
    this->ChanceToUseStaticSpawnPoints = 0.00f;
    this->StaticSpawnPointType = EStaticSpawnPointSelectionType::Any;
}

