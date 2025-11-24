#include "WorkbenchItemWidget.h"

UWorkbenchItemWidget::UWorkbenchItemWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->ChoiceCount = 2;
    this->ItemData = NULL;
}

bool UWorkbenchItemWidget::SelectItemUpgrade(UObject* InUpgrade) {
    return false;
}

void UWorkbenchItemWidget::Refresh() {
}


void UWorkbenchItemWidget::InitializeForUse() {
}


