#include "BXEObjectivePickupActor.h"

ABXEObjectivePickupActor::ABXEObjectivePickupActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ScannerArea = NULL;
    this->Objective = NULL;
}

void ABXEObjectivePickupActor::RewardObtained() {
}


