#include "DecorationSplineComponent.h"

UDecorationSplineComponent::UDecorationSplineComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->Mobility = EComponentMobility::Stationary;
}


