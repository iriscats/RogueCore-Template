#include "LockedRoomActor.h"

ALockedRoomActor::ALockedRoomActor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Objective = NULL;
}

void ALockedRoomActor::SetObjective(UBXEBlueprintControlledObjective* InObjective) {
}


