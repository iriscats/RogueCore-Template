#include "Gem.h"
#include "CarriableInstantUsable.h"

AGem::AGem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->usable = CreateDefaultSubobject<UCarriableInstantUsable>(TEXT("usable"));
    this->ResourceType = NULL;
    this->SpawnedByObjective = NULL;
    this->OverrideResourceAmount = -1.00f;
    this->ResourceAmount = 1.00f;
    this->hasBeenReleased = false;
}

void AGem::SetResourceAmount(float amount) {
}

void AGem::SetHasBeenReleased(bool NewHasBeenReleased) {
}

bool AGem::GetHasBeenReleased() const {
    return false;
}


