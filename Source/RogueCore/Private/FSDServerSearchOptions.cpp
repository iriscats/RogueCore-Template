#include "FSDServerSearchOptions.h"

FFSDServerSearchOptions::FFSDServerSearchOptions() {
    this->JoinStatus = ESteamServerJoinStatus::Open;
    this->SearchRegion = ESteamSearchRegion::Close;
    this->DeepDive = false;
    this->missionSeed = 0;
    this->GlobalMissionSeed = 0;
}

