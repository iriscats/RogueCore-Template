#include "BXEStatCounterComponent.h"

UBXEStatCounterComponent::UBXEStatCounterComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TotalDamageDealtText = FText::FromString(TEXT("Total Damage Dealt: {value}"));
    this->TotalDamageTakenText = FText::FromString(TEXT("Total Damage Taken: {value}"));
    this->HealthText = FText::FromString(TEXT("Health: {value}"));
    this->ShieldText = FText::FromString(TEXT("Shield: {value}"));
    this->Character = NULL;
}

void UBXEStatCounterComponent::OnPlayerHealthChanged(float Health) {
}

FText UBXEStatCounterComponent::GetStatsTextForUI() const {
    return FText::GetEmpty();
}


