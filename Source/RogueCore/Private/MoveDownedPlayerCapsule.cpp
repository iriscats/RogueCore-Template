#include "MoveDownedPlayerCapsule.h"

UMoveDownedPlayerCapsule::UMoveDownedPlayerCapsule(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->CanCharacterStepUpOn = ECB_No;
    this->IsRepelling = false;
}


