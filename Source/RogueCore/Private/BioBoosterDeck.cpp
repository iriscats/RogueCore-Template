#include "BioBoosterDeck.h"

UBioBoosterDeck::UBioBoosterDeck() {
    this->BelongsToClass = NULL;
    this->Icon = NULL;
    this->EnableDangerousSaveGameIDEditing = false;
}

TArray<FRewardDispenserReward> UBioBoosterDeck::GetRandomRewardUnlocks(int32 InCount, UWorld* Context, FRandomStream& InRandomStream) {
    return TArray<FRewardDispenserReward>();
}


