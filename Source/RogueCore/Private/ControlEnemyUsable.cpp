#include "ControlEnemyUsable.h"

UControlEnemyUsable::UControlEnemyUsable(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->usable = true;
    this->TurnOffAfterUse = true;
}


