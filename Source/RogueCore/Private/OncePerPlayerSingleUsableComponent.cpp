#include "OncePerPlayerSingleUsableComponent.h"
#include "Net/UnrealNetwork.h"

UOncePerPlayerSingleUsableComponent::UOncePerPlayerSingleUsableComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->IsClientPredictive = true;
}


void UOncePerPlayerSingleUsableComponent::OnRep_Users() {
}

void UOncePerPlayerSingleUsableComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UOncePerPlayerSingleUsableComponent, ExcludedUsers);
}


