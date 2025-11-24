#include "BasicButtonWidget.h"

UBasicButtonWidget::UBasicButtonWidget() {
    this->InnerButton = NULL;
    this->AnimButtonClicked = NULL;
    this->AnimButtonHovered = NULL;
    this->AnimButtonUnhovered = NULL;
    this->NativeButton = NULL;
    this->bButtonHovered = false;
}




void UBasicButtonWidget::NativeButtonUnhovered() {
}

void UBasicButtonWidget::NativeButtonHovered() {
}

void UBasicButtonWidget::NativeButtonClicked() {
}


