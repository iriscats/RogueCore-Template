#include "FSDServerListClient.h"

UFSDServerListClient::UFSDServerListClient() {
    this->IsInProgress = false;
}

bool UFSDServerListClient::StopHosting() {
    return false;
}

bool UFSDServerListClient::StartHosting(const FString& RunName) {
    return false;
}

void UFSDServerListClient::ListLobbys() {
}

FSessionSearchResultWrapper UFSDServerListClient::CreateSessionData(FServerlistLobby FromLobby) {
    return FSessionSearchResultWrapper{};
}

int32 UFSDServerListClient::CalculateRemoteServerPing(const FString& RemoteServerSteamLocation) {
    return 0;
}


