#include "CollectableResourceData.h"

UCollectableResourceData::UCollectableResourceData() {
    this->ScaleToRoomResourceMultiplier = false;
    this->ResourceCreator = NULL;
    this->Positioning = NULL;
    this->Rarity = 0.00f;
    this->InfluenceRadius = 250.00f;
    this->UseTerrainPlacement = false;
}

float UCollectableResourceData::GetDesiredAmount(AProceduralSetup* pls) const {
    return 0.0f;
}


