#include "AccessRequirementComponent.h"

UAccessRequirementComponent::UAccessRequirementComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->AccessCondition = NULL;
}

UAccessCondition* UAccessRequirementComponent::GetAccessCondition() const {
    return NULL;
}


