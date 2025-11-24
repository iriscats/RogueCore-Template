#include "StaticSpawnPointManager.h"

UStaticSpawnPointManager::UStaticSpawnPointManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->IsDirty = true;
}


