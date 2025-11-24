#include "PathfinderCollisionComponent.h"

UPathfinderCollisionComponent::UPathfinderCollisionComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bHiddenInGame = true;
    this->ActivatePFCollisionAtInit = false;
    this->PFColiType = PFCollisionType::SolidWalkable;
    this->ShowInTerrainScanner = true;
}

void UPathfinderCollisionComponent::OnInitialGenerationDone() {
}

bool UPathfinderCollisionComponent::IsInsideConvex(FVector SamplePosition) const {
    return false;
}

void UPathfinderCollisionComponent::DisablePFCollision() {
}

void UPathfinderCollisionComponent::ActivatePFCollision() {
}


