#include "FirstPersonSkeletalMeshComponent.h"
#include "UObject/UnrealType.h"

UFirstPersonSkeletalMeshComponent::UFirstPersonSkeletalMeshComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DepthPriorityGroup = SDPG_Foreground;
    this->FirstPersonPrimitiveType = EFirstPersonPrimitiveType::FirstPerson;
}

void UFirstPersonSkeletalMeshComponent::SetFirstPersonFOVEnabled(bool bEnabled) {
}

bool UFirstPersonSkeletalMeshComponent::GetSetFirstPersonFOVEnabled() {
    return false;
}

FVector UFirstPersonSkeletalMeshComponent::CalcFirstPersonFOVPositionCorrection(APlayerController* PlayerController, const FVector& origPos) {
    return FVector{};
}


