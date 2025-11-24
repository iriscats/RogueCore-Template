#include "IntelChallengeForResource.h"

UIntelChallengeForResource::UIntelChallengeForResource() {
    this->RequiredResource = NULL;
    this->RequiredAmount = 1;
    this->RequiredZone = NULL;
    this->RequireMutator = false;
    this->AllowCollectionOverMultipleRuns = true;
    this->CanTeammatesDeposit = true;
}

void UIntelChallengeForResource::OnResourceIncreased(UCappedResource* Resource, const float ChangeAmount) {
}

void UIntelChallengeForResource::OnResourceDeposited(UResourceData* Resource, const float change) {
}


