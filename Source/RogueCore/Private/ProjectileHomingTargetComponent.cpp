#include "ProjectileHomingTargetComponent.h"

UProjectileHomingTargetComponent::UProjectileHomingTargetComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Radius = -1.00f;
    this->LockonDelay = 0.00f;
    this->OnlyIncludePawnsWithAttitude = 0;
    this->AquireOnBeginPlay = true;
    this->UnlockOnTargetDeath = false;
}

void UProjectileHomingTargetComponent::OnTargetDeath(UHealthComponentBase* Health) {
}

void UProjectileHomingTargetComponent::AquireTarget() {
}


