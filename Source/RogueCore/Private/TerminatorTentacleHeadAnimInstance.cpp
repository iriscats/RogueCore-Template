#include "TerminatorTentacleHeadAnimInstance.h"

UTerminatorTentacleHeadAnimInstance::UTerminatorTentacleHeadAnimInstance(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer) {
    this->Idle = false;
    this->Grabbing = false;
    this->Grabbed = false;
}


