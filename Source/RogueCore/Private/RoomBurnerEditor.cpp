#include "RoomBurnerEditor.h"

ARoomBurnerEditor::ARoomBurnerEditor(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->bAlwaysRelevant = true;
    this->bReplicates = true;
    const FProperty* p_RemoteRole = GetClass()->FindPropertyByName("RemoteRole");
    (*p_RemoteRole->ContainerPtrToValuePtr<TEnumAsByte<ENetRole>>(this)) = ROLE_SimulatedProxy;
    this->LiveUpdateEditor = false;
    this->MirrorTest = ERoomMirror::None;
    this->OverridePLSCLass = NULL;
    this->RoomGenerator = NULL;
    this->RoomRadius = 2500.00f;
    this->MirrorSupport = ERoomMirroringSupport::MirrorAroundX;
    this->ShowRoomCollider = false;
    this->ShowLineCarvers = true;
    this->Seed = -1;
    this->RunDepth = ERunDepth::Depth1;
    this->RunTemplate = NULL;
    this->ActiveStage = -1;
    this->Biome = NULL;
    this->PlanetZone = NULL;
    this->DifficultyOverride = NULL;
    this->BossOverride = NULL;
    this->Difficulty = NULL;
    this->ForcePlayerCount = -1;
    this->GenerateDebris = true;
    this->GenerateItems = true;
    this->GenerateResources = true;
    this->SpawnEncounters = true;
    this->TestEnemy = NULL;
    this->TestEnemyCount = 0;
    this->TestSpecialEvent = NULL;
    this->TestTreasure = NULL;
    this->CSGWorld = NULL;
    this->PLSLiveEditor = NULL;
    this->LiveEditRoomGenerator = NULL;
}

void ARoomBurnerEditor::SpawnEncounter(AProceduralSetup* setup) {
}

URoomGenerator* ARoomBurnerEditor::GetRoomGenerator() const {
    return NULL;
}


