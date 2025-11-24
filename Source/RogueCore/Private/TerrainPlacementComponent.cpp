#include "TerrainPlacementComponent.h"

UTerrainPlacementComponent::UTerrainPlacementComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Mobility = EComponentMobility::Stationary;
    this->CapsuleType = EDebrisColliderType::Object;
    this->BlockerIDHack = -1;
    this->bAddBlockerOnSpawn = false;
}

void UTerrainPlacementComponent::RemoveBlockers() {
}

void UTerrainPlacementComponent::AddBlockers(AProceduralSetup* ProceduralSetup, const FTransform& Transform) {
}


