#include "EscortMuleTrack.h"

AEscortMuleTrack::AEscortMuleTrack(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

bool AEscortMuleTrack::HasMatchingGameplayTag(FGameplayTag TagToCheck) const {
    return false;
}


