#include "EnhancementPerkLibrary.h"

UEnhancementPerkLibrary::UEnhancementPerkLibrary() {
}

void UEnhancementPerkLibrary::SetEquippedEnhancementPerks(const UObject* WorldContext, UPlayerCharacterID* Character, const TArray<UPerkAsset*>& Perks) {
}

TArray<UPerkAsset*> UEnhancementPerkLibrary::GetUnlockedEnhancementPerks(const UObject* WorldContext) {
    return TArray<UPerkAsset*>();
}

int32 UEnhancementPerkLibrary::GetTotalNumberOfEnhancementSlots(const UObject* WorldContext) {
    return 0;
}

int32 UEnhancementPerkLibrary::GetNumberOfUnlockedEnhancementSlots(const UObject* WorldContext) {
    return 0;
}

TArray<UPerkAsset*> UEnhancementPerkLibrary::GetEquippedEnhancementPerks(const UObject* WorldContext, UPlayerCharacterID* characterID) {
    return TArray<UPerkAsset*>();
}

int32 UEnhancementPerkLibrary::GetEnhancementSlotsUnlockRank(const UObject* WorldContext, int32 SlotIndex) {
    return 0;
}

int32 UEnhancementPerkLibrary::GetAmountOfUnlockedEnhancementPerks(const UObject* WorldContext) {
    return 0;
}

TArray<UPerkAsset*> UEnhancementPerkLibrary::GetAllEnhancementPerks(const UObject* WorldContext) {
    return TArray<UPerkAsset*>();
}


