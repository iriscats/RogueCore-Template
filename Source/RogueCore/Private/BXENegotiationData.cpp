#include "BXENegotiationData.h"

FBXENegotiationData::FBXENegotiationData() {
    this->bNegotiating = false;
    this->SkipUnlock = NULL;
    this->ActiveParticipant = 0;
    this->Timeout = 0;
    this->Level = 0;
}

