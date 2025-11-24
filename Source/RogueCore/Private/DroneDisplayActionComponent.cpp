#include "DroneDisplayActionComponent.h"
#include "Runtime/Engine/Classes/Components/TextRenderComponent.h"

UDroneDisplayActionComponent::UDroneDisplayActionComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DisplayText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Text"));
}

void UDroneDisplayActionComponent::SetMode(EDroneActions droneAction) {
}


