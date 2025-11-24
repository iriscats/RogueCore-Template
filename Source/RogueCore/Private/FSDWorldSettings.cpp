#include "FSDWorldSettings.h"

AFSDWorldSettings::AFSDWorldSettings(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DebugInventoryList = NULL;
    this->DefaultCharacterClass = NULL;
    this->ClientCharacterClass = NULL;
    this->bSpawnInGameActors = true;
}


