#include "BlitzUnlockComponent.h"
#include "Net/UnrealNetwork.h"

UBlitzUnlockComponent::UBlitzUnlockComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->MaximumMoveSpeed = 1500.00f;
    this->DistanceToMove = 700.00f;
    this->StopDistance = 100.00f;
    this->MaximumBlitzAirTime = 0.50f;
    this->IsBlitzingLocally = false;
}

void UBlitzUnlockComponent::StopBlitz() {
}

void UBlitzUnlockComponent::StartBlitzInCameraDirection() {
}

void UBlitzUnlockComponent::ServerSetMovementState_Implementation(const FBlitzMovementState& NewMovementState) {
}

void UBlitzUnlockComponent::OnReplicateMovementState() {
}



void UBlitzUnlockComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UBlitzUnlockComponent, MovementState);
}


