#include "LockedRoomObjectiveSpawner.h"
#include "Net/UnrealNetwork.h"

ALockedRoomObjectiveSpawner::ALockedRoomObjectiveSpawner(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Objective = NULL;
    this->RoomInstance = NULL;
}

void ALockedRoomObjectiveSpawner::SetLockedRoomObjective(UBXELockedRoomObjective* NewObjective) {
}


void ALockedRoomObjectiveSpawner::OnRep_RoomInstance() {
}

void ALockedRoomObjectiveSpawner::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ALockedRoomObjectiveSpawner, Objective);
    DOREPLIFETIME(ALockedRoomObjectiveSpawner, RoomInstance);
}


