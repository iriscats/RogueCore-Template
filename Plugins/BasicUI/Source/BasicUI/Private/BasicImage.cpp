#include "BasicImage.h"

UBasicImage::UBasicImage() {
    this->InnerImage = NULL;
}

void UBasicImage::SetDynamicMaterialVector(FName InName, FVector4 InVector) {
}

void UBasicImage::SetDynamicMaterialTexture(FName InName, UTexture2D* InTexture) {
}

void UBasicImage::SetDynamicMaterialScalar(FName InName, float InValue) {
}

void UBasicImage::SetDynamicMaterialParameters(FBasicMaterialParameters InParameters) {
}

void UBasicImage::SetDynamicMaterialColor(FName InName, FBasicColor InColor) {
}

void UBasicImage::SetBrushFromTexture(UTexture2D* InTexture, bool InMatchSize) {
}

void UBasicImage::SetBrushColor(FBasicColor InColor) {
}

void UBasicImage::SetBrush(FBasicBrush InBrush) {
}

FSlateBrush UBasicImage::GetSlateBrush() {
    return FSlateBrush{};
}

UMaterialInstanceDynamic* UBasicImage::GetDynamicMaterial() {
    return NULL;
}


