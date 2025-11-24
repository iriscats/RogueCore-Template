#include "PlayerControllerLevelEndState.h"

FPlayerControllerLevelEndState::FPlayerControllerLevelEndState() {
    this->HasLevelEnded = false;
    this->IsMissionAborted = false;
    this->IsAllDwarvesDown = false;
    this->NumberOfCompletedStages = 0;
}

