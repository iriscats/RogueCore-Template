#include "ButtonWidget.h"

UButtonWidget::UButtonWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->DataIndex = 0;
    this->DataObject = NULL;
    this->DataBool = false;
    this->AnimHoveringPlaybackSpeed = 1.00f;
    this->AnimClickedPlaybackSpeed = 1.00f;
    this->bButtonHovered = false;
    this->bButtonEnabled = true;
    this->MainButton = NULL;
    this->AnimHovering = NULL;
    this->AnimClicked = NULL;
}

void UButtonWidget::SetButtonEnabled(bool InIsEnabled) {
}

void UButtonWidget::SetButtonData(int32 InDataIndex, UObject* InDataObject, const FString& InDataString, bool InDataBool) {
}




void UButtonWidget::ButtonUnhovered() {
}

void UButtonWidget::ButtonHovered() {
}

void UButtonWidget::ButtonClicked() {
}


