#include "CharacterSettings.h"

UCharacterSettings::UCharacterSettings() {
    this->BoscoID = NULL;
    this->DefaultCharacterID = NULL;
    this->DefaultEditorCharacterID = NULL;
    this->ThrowItemAnimSettings = NULL;
    this->AutoReloadShout = NULL;
    this->TeleportPositioning = NULL;
    this->TeleportPlacement = NULL;
}

UPlayerCharacterID* UCharacterSettings::GetPlayerCharacterID(const FGuid& ID) const {
    return NULL;
}

UInventoryList* UCharacterSettings::GetInventoryList() const {
    return NULL;
}


