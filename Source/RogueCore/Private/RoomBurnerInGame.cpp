#include "RoomBurnerInGame.h"

ARoomBurnerInGame::ARoomBurnerInGame(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->LiveUpdateEditor = false;
    this->RoomGenerator = NULL;
    this->RoomRadius = 2500.00f;
    this->ShowRoomCollider = false;
    this->RunDepth = ERunDepth::Depth1;
    this->RunTemplate = NULL;
    this->ActiveStage = -1;
    this->Seed = -1;
    this->Biome = NULL;
    this->PlanetZone = NULL;
    this->DifficultyOverride = NULL;
    this->Difficulty = NULL;
    this->ForcePlayerCount = -1;
    this->GenerateDebris = true;
    this->GenerateItems = true;
    this->GenerateResources = true;
    this->SpawnEncounters = true;
    this->CSGWorld = NULL;
    this->PLSLiveEditor = NULL;
    this->CaveGeneratorPLSOverride = NULL;
    this->LiveEditRoomGenerator = NULL;
}

URoomGenerator* ARoomBurnerInGame::GetRoomGenerator() const {
    return NULL;
}


