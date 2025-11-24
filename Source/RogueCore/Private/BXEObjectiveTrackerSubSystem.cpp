#include "BXEObjectiveTrackerSubSystem.h"

UBXEObjectiveTrackerSubSystem::UBXEObjectiveTrackerSubSystem() {
}

bool UBXEObjectiveTrackerSubSystem::UpdateObjectiveState(UBXEBlueprintControlledObjective* InObjective, EObjectiveState InState) {
    return false;
}

void UBXEObjectiveTrackerSubSystem::UpdateObjectiveFailReason(UBXEBlueprintControlledObjective* InObjective, EObjectiveFailReason InReason) {
}

void UBXEObjectiveTrackerSubSystem::RegisterObjective(UBXEBlueprintControlledObjective* InObjective) {
}

void UBXEObjectiveTrackerSubSystem::RecordExpeniteTarget(UBXEBlueprintControlledObjective* InObjective, float InAmount) {
}

void UBXEObjectiveTrackerSubSystem::RecordExpeniteSpawned(UBXEBlueprintControlledObjective* InObjective, float InAmount) {
}

void UBXEObjectiveTrackerSubSystem::RecordExpeniteReceived(UBXEBlueprintControlledObjective* InObjective, float InAmount) {
}

UBXEBlueprintControlledObjective* UBXEObjectiveTrackerSubSystem::FindObjectiveFromActor(const AActor* InObjectiveActor) const {
    return NULL;
}


