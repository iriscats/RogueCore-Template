#include "IntelChallengeForStat.h"

UIntelChallengeForStat::UIntelChallengeForStat() {
    this->RequiredStat = NULL;
    this->RequiredAmount = 1;
    this->RequiredZone = NULL;
    this->RequireMutator = false;
}

void UIntelChallengeForStat::OnStatUpdated(UObject* WorldContext, UMissionStat* ChangedStat, float Value, float change) {
}


