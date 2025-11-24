#include "ProceduralTunnelComponent.h"

UProceduralTunnelComponent::UProceduralTunnelComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->TunnelParameters = NULL;
    this->MaxAngleFromLastPointToEntrance = 50.00f;
    this->CreateDirt = true;
    this->DirtInfluencer = NULL;
    this->DirtInfluencerRange = 100.00f;
    this->MaxDirtRangeToSurface = 300.00f;
}


