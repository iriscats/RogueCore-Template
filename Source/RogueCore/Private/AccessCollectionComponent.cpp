#include "AccessCollectionComponent.h"
#include "Net/UnrealNetwork.h"

UAccessCollectionComponent::UAccessCollectionComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UAccessCollectionComponent::RemoveCondition_Implementation(UAccessCondition* Condition) {
}

bool UAccessCollectionComponent::HasCondition(const UAccessCondition* Condition) const {
    return false;
}

void UAccessCollectionComponent::AddCondition_Implementation(UAccessCondition* Condition) {
}

void UAccessCollectionComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UAccessCollectionComponent, AccessConditions);
}


