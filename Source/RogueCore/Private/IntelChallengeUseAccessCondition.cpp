#include "IntelChallengeUseAccessCondition.h"

UIntelChallengeUseAccessCondition::UIntelChallengeUseAccessCondition() {
    this->RequiredAccess = NULL;
    this->RequiredUseAmount = 1;
}

void UIntelChallengeUseAccessCondition::OnUsableTriggered(UUsableComponentBase* usable) {
}


