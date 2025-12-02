#include "BasicPanel.h"
#include "UObject/UnrealType.h"
#include "Templates/SubclassOf.h"

UBasicPanel::UBasicPanel() {
}

TArray<UWidget*> UBasicPanel::CreateChildren(TSubclassOf<UWidget> InWidgetClass, int32 InNumChildren, FBasicSlotSettings InSlotSettings, bool InClearPanelBefore) {
    return TArray<UWidget*>();
}

UWidget* UBasicPanel::CreateChild(TSubclassOf<UWidget> InWidgetClass, FBasicSlotSettings InSlotSettings) {
    return NULL;
}

UBasicSlot* UBasicPanel::AddChildToPanel(UWidget* InChild, FBasicSlotSettings InSlotSettings) {
    return NULL;
}

void UBasicPanel::AddChildren(const TArray<UWidget*> InChildren, FBasicSlotSettings InSlotSettings, bool InClearPanelBefore) {
}


