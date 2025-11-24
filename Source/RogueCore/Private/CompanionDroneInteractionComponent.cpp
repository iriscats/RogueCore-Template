#include "CompanionDroneInteractionComponent.h"

UCompanionDroneInteractionComponent::UCompanionDroneInteractionComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->InteractionTime = 0.00f;
    this->CanUse = true;
    this->DisableOnuse = true;
}

void UCompanionDroneInteractionComponent::StopUsing() {
}

void UCompanionDroneInteractionComponent::StartUsing(float interactionSpeed) {
}

bool UCompanionDroneInteractionComponent::IsInUse() const {
    return false;
}

bool UCompanionDroneInteractionComponent::GetCanUse() const {
    return false;
}


