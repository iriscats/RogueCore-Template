#include "RiskVector.h"

URiskVector::URiskVector() {
    this->OptionalExtraObjective = NULL;
    this->DoubleWarning = true;
    this->ShowInUserInterface = true;
    this->Icon = NULL;
    this->CampaignIcon = NULL;
    this->Header = NULL;
    this->VoteOptionActionType = EVoteOptionActionType::NEGATIVE;
    this->bVoteRepeatable = false;
    this->bRunPersistent = true;
}

FText URiskVector::GetRichDescription() const {
    return FText::GetEmpty();
}


