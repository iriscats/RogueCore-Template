#include "CampaignMission.h"

UCampaignMission::UCampaignMission() {
    this->PlanetZone = NULL;
    this->MissionCompleteShout = NULL;
    this->OverrideMutators = false;
    this->MutatorOverride = ECampaignMutators::NotAllowed;
}

UStageTemplate* UCampaignMission::GetMissionTemplate() const {
    return NULL;
}


