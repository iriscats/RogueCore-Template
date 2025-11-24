#include "SplineLevelGenerationCarverComponent.h"

USplineLevelGenerationCarverComponent::USplineLevelGenerationCarverComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TerrainType = NULL;
    this->TerrainMaterial = NULL;
    this->CarveRadius = 100.00f;
    this->ConvexExpensiveNoise = 0.00f;
    this->Filter = ECarveFilterType::ReplaceAll;
    this->CarveInPass = EDebrisItemPass::PrePlacement;
    this->UseCarveInPass = false;
    this->SelfActivate = true;
    this->CarvingDisabled = false;
}

void USplineLevelGenerationCarverComponent::AddCarverComponentToProceduralSetup() {
}


