#include "TerrainMaterialCore.h"

UTerrainMaterialCore::UTerrainMaterialCore() {
    this->BurntMaterial = NULL;
    this->BulletBurntMaterial = NULL;
    this->PathfinderDanger = false;
    this->PathfinderPreventSpawning = false;
    this->ScannerMaterial = NULL;
    this->NumDynamicRenderMaterialInstances = 0;
    this->InstancingDuration = 5.00f;
    this->LastDynamicIndex = 0;
}


