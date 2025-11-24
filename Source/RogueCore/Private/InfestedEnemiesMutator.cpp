#include "InfestedEnemiesMutator.h"

UInfestedEnemiesMutator::UInfestedEnemiesMutator() {
    this->SpawnEffects.AddDefaulted(5);
}

UFXSystemAsset* UInfestedEnemiesMutator::GetParticleSystem(AFSDPawn* Enemy) const {
    return NULL;
}


