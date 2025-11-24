#include "StaticSpawnPoint.h"

UStaticSpawnPoint::UStaticSpawnPoint(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->IsUsed = false;
    this->Type = EStaticSpawnPointType::Small;
}


