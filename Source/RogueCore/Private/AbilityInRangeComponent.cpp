#include "AbilityInRangeComponent.h"

UAbilityInRangeComponent::UAbilityInRangeComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->UpdateTime = 0.24f;
    this->CacheUpdateTime = 0.50f;
}

bool UAbilityInRangeComponent::ShouldCountActor_Implementation(AActor* Actor) const {
    return false;
}



bool UAbilityInRangeComponent::IsAnyActorInRange() const {
    return false;
}

TArray<AActor*> UAbilityInRangeComponent::GetRelevantActors_Implementation() const {
    return TArray<AActor*>();
}

float UAbilityInRangeComponent::GetMaxRadius_Implementation() const {
    return 0.0f;
}

TArray<AActor*> UAbilityInRangeComponent::GetActorsInRange() const {
    return TArray<AActor*>();
}


