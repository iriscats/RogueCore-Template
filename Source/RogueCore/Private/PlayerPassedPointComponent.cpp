#include "PlayerPassedPointComponent.h"

UPlayerPassedPointComponent::UPlayerPassedPointComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DisableOnFirstPlayerInFront = true;
}

void UPlayerPassedPointComponent::OnMatchStarted() {
}


