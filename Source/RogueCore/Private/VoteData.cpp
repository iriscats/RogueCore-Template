#include "VoteData.h"

FVoteData::FVoteData() {
    this->bVoting = false;
    this->VoteWinnerIndex = 0;
    this->Timeout = 0;
    this->CountDownStarted = false;
    this->VoteID = 0;
}

