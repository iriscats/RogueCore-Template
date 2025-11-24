#include "LightModulationComponent.h"

ULightModulationComponent::ULightModulationComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->PhotoSensitiveMaterialModifier = 0.10f;
    this->PhotoSensitiveLightModifier = 0.10f;
    this->Loop = true;
    this->AffectedByPhotosensitivity = true;
    this->RandomStartTime = true;
}

void ULightModulationComponent::StopModulation() {
}

void ULightModulationComponent::StartModulation() {
}

void ULightModulationComponent::SetLightCount(int32 lightCount) {
}

void ULightModulationComponent::AddMaterial(UMaterialInstanceDynamic* Material, const FName& Param, float MaxIntensity) {
}

void ULightModulationComponent::AddLight(UPointLightComponent* Light, float MaxIntensity) {
}


