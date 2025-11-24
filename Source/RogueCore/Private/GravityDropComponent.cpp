#include "GravityDropComponent.h"
#include "Net/UnrealNetwork.h"

UGravityDropComponent::UGravityDropComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->IsDropping = false;
    this->InitialDropSpeed = 0.00f;
}

void UGravityDropComponent::OnRep_IsDropping() {
}

void UGravityDropComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UGravityDropComponent, IsDropping);
    DOREPLIFETIME(UGravityDropComponent, InitialDropSpeed);
}


