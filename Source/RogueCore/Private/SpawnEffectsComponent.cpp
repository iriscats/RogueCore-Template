#include "SpawnEffectsComponent.h"

USpawnEffectsComponent::USpawnEffectsComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->BiomeMaterialOverride = NULL;
}

void USpawnEffectsComponent::All_AddEffects_Implementation(const TArray<FSpawnEffectItem>& NewEffects) {
}


