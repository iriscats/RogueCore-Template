#include "DebrisStaticMesh.h"

FDebrisStaticMesh::FDebrisStaticMesh() {
    this->mesh = NULL;
    this->Material = NULL;
    this->CollisionProfile = EDebrisMeshCollisionProfile::NoCollision;
    this->Probablity = 0.00f;
    this->DestroyedSound = NULL;
    this->DestroyedParticles = NULL;
    this->Fragile = false;
    this->ExtraClearRadius = 0.00f;
    this->CastShadows = EDebrisMeshShadows::Never;
    this->Durable = false;
    this->SpecialDebrisType = 0;
    this->SpawnWhenCarving = false;
    this->OnlySpawnWhenCarving = false;
}

