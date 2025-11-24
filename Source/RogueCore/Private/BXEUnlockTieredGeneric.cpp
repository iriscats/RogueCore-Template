#include "BXEUnlockTieredGeneric.h"

UBXEUnlockTieredGeneric::UBXEUnlockTieredGeneric() {
    this->UnlockUsesRandomRarity = true;
}

TArray<UBXEUnlockRarity*> UBXEUnlockTieredGeneric::GetAvailableRarities() {
    return TArray<UBXEUnlockRarity*>();
}


