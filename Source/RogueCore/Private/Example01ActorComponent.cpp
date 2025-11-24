#include "Example01ActorComponent.h"
#include "Net/UnrealNetwork.h"

UExample01ActorComponent::UExample01ActorComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TargetTrackingTime = 0.00f;
    this->TargetCounter = 0;
}

void UExample01ActorComponent::SetTarget(AActor* NewTarget) {
}

void UExample01ActorComponent::OnRep_State(const FExample01State& oldState) {
}

int32 UExample01ActorComponent::GetTargetCount() const {
    return 0;
}

float UExample01ActorComponent::GetCurrentTargetTime() const {
    return 0.0f;
}

AActor* UExample01ActorComponent::GetCurrentTarget() const {
    return NULL;
}

void UExample01ActorComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UExample01ActorComponent, State);
    DOREPLIFETIME(UExample01ActorComponent, TargetCounter);
}


