#include "IntelChallengeForUpgrade.h"

UIntelChallengeForUpgrade::UIntelChallengeForUpgrade() {
    this->RequiredType = EUnlockType::Upgrade;
    this->RequiredAmount = 1;
    this->AllowCollectionOverMultipleRuns = false;
}

void UIntelChallengeForUpgrade::OnLevelUp(const int32 Level, const TArray<UBXEUnlockBase*>& Unlocks) {
}


