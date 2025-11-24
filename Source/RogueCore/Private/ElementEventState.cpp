#include "ElementEventState.h"

FElementEventState::FElementEventState() {
    this->EventType = NULL;
    this->TriggeredByElementType = NULL;
    this->Source = NULL;
    this->StartTime = 0.00f;
    this->LockDuration = 0.00f;
}

