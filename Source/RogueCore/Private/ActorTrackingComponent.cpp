#include "ActorTrackingComponent.h"

UActorTrackingComponent::UActorTrackingComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->WidgetType = NULL;
    this->VisibleOnHoldTAB = true;
    this->VisibleFromStart = false;
    this->bIconHidden = false;
}

void UActorTrackingComponent::ToggleIcon(bool visible) {
}

void UActorTrackingComponent::ShowAlwaysOn() {
}

void UActorTrackingComponent::OnHoldTAB(bool IsDown) {
}


