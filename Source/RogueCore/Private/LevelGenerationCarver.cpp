#include "LevelGenerationCarver.h"

FLevelGenerationCarver::FLevelGenerationCarver() {
    this->MeshCarver = NULL;
    this->ConvexCarver = NULL;
    this->StaticMeshCarver = NULL;
    this->CSGCarver = NULL;
    this->ConvexExpensiveNoise = 0.00f;
    this->CarveCellSize = CarveOptionsCellSize::CARVE_CELL_SIZE_25;
    this->TerrainMaterial = NULL;
    this->Type = ELevelCarverType::None;
    this->Filter = ECarveFilterType::ReplaceAll;
    this->CarvePass = EDebrisItemPass::PrePlacement;
    this->UseCarvePass = false;
    this->ToBeDiscarded = false;
}

