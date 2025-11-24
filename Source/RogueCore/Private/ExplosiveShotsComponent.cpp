#include "ExplosiveShotsComponent.h"

UExplosiveShotsComponent::UExplosiveShotsComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Sound = NULL;
    this->Effect = NULL;
}

void UExplosiveShotsComponent::All_ShowEffects_Implementation(const FVector_NetQuantize& Location) {
}


