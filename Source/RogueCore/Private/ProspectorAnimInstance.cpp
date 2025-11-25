#include "ProspectorAnimInstance.h"

UProspectorAnimInstance::UProspectorAnimInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->ProspectorState = EProspectorRobotState::Searching;
    this->ArmBusyness = 0.00f;
}


