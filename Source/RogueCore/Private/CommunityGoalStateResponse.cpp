#include "CommunityGoalStateResponse.h"

FCommunityGoalStateResponse::FCommunityGoalStateResponse() {
    this->IsGoal = false;
    this->IsRecruitment = false;
    this->FreeBeers = false;
    this->TimeLeftSeconds = 0.00f;
    this->LastUpdateGoalsID = 0;
    this->CurrentGoalPeriodID = 0;
}

