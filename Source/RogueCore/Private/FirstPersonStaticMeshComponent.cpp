#include "FirstPersonStaticMeshComponent.h"
#include "UObject/UnrealType.h"

UFirstPersonStaticMeshComponent::UFirstPersonStaticMeshComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DepthPriorityGroup = SDPG_Foreground;
    this->CastShadow = false;
    this->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::FirstPerson;
    this->EnabledFPFOV = true;
}

void UFirstPersonStaticMeshComponent::SetEnabledFPFOV(bool FOV) {
}

bool UFirstPersonStaticMeshComponent::GeEnabledFPFOV() const {
    return false;
}


