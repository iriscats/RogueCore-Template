#include "DropToTerrainComponent.h"
#include "Net/UnrealNetwork.h"

UDropToTerrainComponent::UDropToTerrainComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->StartActive = false;
    this->FallVelocity = 0.00f;
    this->TerrainTraceMaxDistance = -10000.00f;
    this->ConnectedPoints = 0;
    this->IsDetecting = false;
    this->IsForceDisabled = false;
}

void UDropToTerrainComponent::StopDropDetection(bool stopFalling) {
}

void UDropToTerrainComponent::OnTerrainRemoved(USceneComponent* Point) {
}

void UDropToTerrainComponent::OnRep_DropTarget() {
}

void UDropToTerrainComponent::ForceDisable() {
}

void UDropToTerrainComponent::BeginDropDetection() {
}

void UDropToTerrainComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UDropToTerrainComponent, DropTarget);
}


