#include "FlyingLifterAnimInstance.h"

UFlyingLifterAnimInstance::UFlyingLifterAnimInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->HasGrabbedPlayer = false;
    this->ToChaseLock = false;
    this->ChaseToWanderLock = false;
    this->ToCarryLock = false;
    this->GrabberState = EGrabberState::StandBy;
}


