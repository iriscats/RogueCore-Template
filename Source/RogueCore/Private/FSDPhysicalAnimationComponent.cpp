#include "FSDPhysicalAnimationComponent.h"

UFSDPhysicalAnimationComponent::UFSDPhysicalAnimationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->HitReactionStrength = 0.50f;
    this->TimeOfHitReaction = 0.50f;
}

void UFSDPhysicalAnimationComponent::RequestPhysicalHitReaction(const FVector& InForce, const FName InBoneName) {
}


