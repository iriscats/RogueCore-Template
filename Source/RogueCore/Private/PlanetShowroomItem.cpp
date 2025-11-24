#include "PlanetShowroomItem.h"

APlanetShowroomItem::APlanetShowroomItem(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->NoHoverMaterial = NULL;
    this->HoverMaterial = NULL;
    this->NoHoverWhenLockedMaterial = NULL;
    this->HoverWhenLockedMaterial = NULL;
    this->NoHoverWhenUnavailableMaterial = NULL;
    this->HoverWhenUnavailableMaterial = NULL;
    this->PlanetMeshComp = NULL;
    this->SelectedDeptht = ERunDepth::Depth1;
}

void APlanetShowroomItem::UpdateMaterialParameters(ERunDepth Depth) {
}



void APlanetShowroomItem::SetupPlanetPoints(TArray<FPlanetPointSetup> InPoints) {
}

void APlanetShowroomItem::SetPlanetViewDepth_Implementation(const ERunDepth Depth) {
}

void APlanetShowroomItem::SetHoveredBiome(FPlanetPointSetup Point) {
}




