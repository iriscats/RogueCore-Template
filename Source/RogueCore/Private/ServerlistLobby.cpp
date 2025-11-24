#include "ServerlistLobby.h"

FServerlistLobby::FServerlistLobby() {
    this->IsInProgress = false;
    this->NumPlayers = 0;
    this->IsFull = false;
    this->IsClassLocked = false;
    this->PasswordProtected = false;
    this->GameVersion = 0;
}

