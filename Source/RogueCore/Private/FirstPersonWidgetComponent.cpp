#include "FirstPersonWidgetComponent.h"

UFirstPersonWidgetComponent::UFirstPersonWidgetComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DepthPriorityGroup = SDPG_Foreground;
    this->MeshMaterialInstance = NULL;
    this->MeshComponent = NULL;
}


