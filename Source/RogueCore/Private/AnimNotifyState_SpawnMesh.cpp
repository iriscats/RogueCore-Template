#include "AnimNotifyState_SpawnMesh.h"

UAnimNotifyState_SpawnMesh::UAnimNotifyState_SpawnMesh() {
    this->mesh = NULL;
    this->HasOverrideMaterial = false;
    this->OverrideMaterial = NULL;
    this->OverrideMaterialSlot = 0;
    this->UseFirstPersonComponent = false;
}


