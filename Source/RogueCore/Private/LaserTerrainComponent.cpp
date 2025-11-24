#include "LaserTerrainComponent.h"

ULaserTerrainComponent::ULaserTerrainComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Type = ELaserPointerTargetType::Chunkable;
}


