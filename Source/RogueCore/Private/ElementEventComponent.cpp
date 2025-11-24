#include "ElementEventComponent.h"

UElementEventComponent::UElementEventComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->EventType = NULL;
    this->TriggeredByElementType = NULL;
    this->Source = NULL;
}

bool UElementEventComponent::FindEventState(FElementEventState& EventState) {
    return false;
}


