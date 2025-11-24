#include "PawnDebugComponent.h"

UPawnDebugComponent::UPawnDebugComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->WidgetComponent = NULL;
    this->HealthComponent = NULL;
    this->InfoComponent = NULL;
}

void UPawnDebugComponent::ShowPawnHealth(bool InWidgetVisible) {
}

void UPawnDebugComponent::OnHealthChanged(float InValue) {
}

void UPawnDebugComponent::OnDeath(UHealthComponentBase* InHealthComponent) {
}


