#include "OncePerPlayerInstantUsableComponent.h"
#include "Net/UnrealNetwork.h"

UOncePerPlayerInstantUsableComponent::UOncePerPlayerInstantUsableComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}


void UOncePerPlayerInstantUsableComponent::OnRep_Users() {
}

void UOncePerPlayerInstantUsableComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UOncePerPlayerInstantUsableComponent, ExcludedUsers);
}


