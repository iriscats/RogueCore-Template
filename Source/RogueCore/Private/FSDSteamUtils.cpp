#include "FSDSteamUtils.h"

UFSDSteamUtils::UFSDSteamUtils() {
}

void UFSDSteamUtils::ResetSteamTicket() {
}

bool UFSDSteamUtils::PlayerIsFollowingUsOnSteam() {
    return false;
}

void UFSDSteamUtils::OpenURLInSteamBrowser(const FString& URL) {
}

void UFSDSteamUtils::OpenSteamSettings() {
}

bool UFSDSteamUtils::IsTextFilteringInitialized() {
    return false;
}

bool UFSDSteamUtils::IsSteamLoaded() {
    return false;
}

bool UFSDSteamUtils::IsDev(APlayerState* PlayerState) {
    return false;
}

bool UFSDSteamUtils::InitializeFilterText() {
    return false;
}

bool UFSDSteamUtils::HasSupporterUpgrade() {
    return false;
}

bool UFSDSteamUtils::HasDeluxeEdition() {
    return false;
}

bool UFSDSteamUtils::HasContentCreatorEdition() {
    return false;
}

FString UFSDSteamUtils::GetSteamTicket() {
    return TEXT("");
}

FString UFSDSteamUtils::GetSteamRegion() {
    return TEXT("");
}

FString UFSDSteamUtils::GetSteamLanguage() {
    return TEXT("");
}

FString UFSDSteamUtils::GetSteamBranchString() {
    return TEXT("");
}

ESteamBranch UFSDSteamUtils::GetSteamBranch() {
    return ESteamBranch::Main;
}

FString UFSDSteamUtils::GetPlayerSteamName() {
    return TEXT("");
}

FString UFSDSteamUtils::GetPlayerSteamID() {
    return TEXT("");
}

bool UFSDSteamUtils::GenerateTokenIfNeeded() {
    return false;
}

FString UFSDSteamUtils::FilterProfanityText(const FString& inputMessage) {
    return TEXT("");
}


