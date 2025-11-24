#include "CrosshairExtensionComponent.h"
#include "Templates/SubclassOf.h"

UCrosshairExtensionComponent::UCrosshairExtensionComponent(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void UCrosshairExtensionComponent::RemoveExtensionClass(const TSubclassOf<UCrosshairExtensionWidget> WidgetClass) {
}

void UCrosshairExtensionComponent::RemoveExtension(UCrosshairExtensionWidget* Widget) {
}

TArray<UCrosshairExtensionWidget*> UCrosshairExtensionComponent::GetExtensions() const {
    return TArray<UCrosshairExtensionWidget*>();
}

TArray<TSubclassOf<UCrosshairExtensionWidget>> UCrosshairExtensionComponent::GetExtensionClasses() const {
    return TArray<TSubclassOf<UCrosshairExtensionWidget>>();
}

UCrosshairExtensionWidget* UCrosshairExtensionComponent::FindExtension(const TSubclassOf<UCrosshairExtensionWidget> WidgetClass) const {
    return NULL;
}

void UCrosshairExtensionComponent::AddExtensionClass(const TSubclassOf<UCrosshairExtensionWidget> WidgetClass) {
}

void UCrosshairExtensionComponent::AddExtension(UCrosshairExtensionWidget* Widget) {
}


