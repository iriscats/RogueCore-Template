#include "BXELastStageObjective.h"

UBXELastStageObjective::UBXELastStageObjective(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->RiftPositioning = NULL;
    this->spawnedRift = NULL;
    this->DetonatorSpawnClass = NULL;
    this->DetonatorPositioning = NULL;
    this->ExplosiveLocationPositioning = NULL;
    this->ExplosiveLocationCount = 2;
    this->MinDistanceBetweenExplosiveTargets = 3500.00f;
    this->MaxDistanceFromRiftToDetonator = 7500.00f;
    this->MinMaxDistanceToDetonator.AddDefaulted(2);
    this->SpawnedDetonator = NULL;
}

void UBXELastStageObjective::OnWiresMerged() {
}

void UBXELastStageObjective::InitialGenerationDone() {
}


