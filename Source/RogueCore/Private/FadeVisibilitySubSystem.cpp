#include "FadeVisibilitySubSystem.h"

UFadeVisibilitySubSystem::UFadeVisibilitySubSystem() {
}

void UFadeVisibilitySubSystem::ScalePrimitive(const UPrimitiveComponent*& Component, FVector StartScale, FVector EndScale, float Duration) {
}

void UFadeVisibilitySubSystem::ScaleOutPrimitive(const UPrimitiveComponent*& Component, float Duration) {
}

void UFadeVisibilitySubSystem::ScaleInPrimitive(const UPrimitiveComponent*& Component, float Duration) {
}

void UFadeVisibilitySubSystem::FadeOutMaterialByName(const UMeshComponent*& Component, FName Name, FName ParameterName, float Duration) {
}

void UFadeVisibilitySubSystem::FadeOutMaterialByIndex(const UMeshComponent*& Component, int32 MaterialIndex, FName ParameterName, float Duration) {
}

void UFadeVisibilitySubSystem::FadeOutLight(const ULightComponent*& Light, float Duration) {
}

void UFadeVisibilitySubSystem::FadeLightToIntensity(ULightComponent* Light, float Duration, float endIntensity) {
}

void UFadeVisibilitySubSystem::FadeLightByCurve(const ULightComponent*& Light, FRuntimeFloatCurve& Curve) {
}

void UFadeVisibilitySubSystem::FadeInMaterialByName(const UMeshComponent*& Component, FName Name, FName ParameterName, float Duration) {
}

void UFadeVisibilitySubSystem::FadeInMaterialByIndex(const UMeshComponent*& Component, int32 MaterialIndex, FName ParameterName, float Duration) {
}

void UFadeVisibilitySubSystem::FadeInLight(const ULightComponent*& Light, float Duration) {
}


