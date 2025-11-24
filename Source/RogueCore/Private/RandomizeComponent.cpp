#include "RandomizeComponent.h"
#include "Net/UnrealNetwork.h"

URandomizeComponent::URandomizeComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ShouldPickOne = false;
    this->ChanceToBeOnPercent = 50.00f;
    this->RandomSeed = -1;
    this->SingleComponentKeepIndex = -1;
}

void URandomizeComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(URandomizeComponent, RandomSeed);
    DOREPLIFETIME(URandomizeComponent, SingleComponentKeepIndex);
}


