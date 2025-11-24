#include "BoosterDeckContainerComponent.h"

UBoosterDeckContainerComponent::UBoosterDeckContainerComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

TArray<FRewardDispenserReward> UBoosterDeckContainerComponent::GetRandomCardsFromRandomDeck(int32 count) {
    return TArray<FRewardDispenserReward>();
}

TArray<UBioBoosterDeck*> UBoosterDeckContainerComponent::GetDecks() const {
    return TArray<UBioBoosterDeck*>();
}


