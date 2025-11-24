#include "BasicButtonHoldIndicator.h"

UBasicButtonHoldIndicator::UBasicButtonHoldIndicator() {
    this->SettingsAsset = NULL;
    this->bOverrideBrushSize = false;
    this->bOverrideHoldDuration = false;
    this->OverrideHoldDuration = 1.00f;
    this->HoldProgress = 0.00f;
    this->bHolding = false;
}

void UBasicButtonHoldIndicator::SetButton(UButton* InButton) {
}

void UBasicButtonHoldIndicator::EndHold() {
}

void UBasicButtonHoldIndicator::ButtonUnhovered() {
}

void UBasicButtonHoldIndicator::ButtonReleased() {
}

void UBasicButtonHoldIndicator::ButtonPressed() {
}

void UBasicButtonHoldIndicator::ButtonHovered() {
}

void UBasicButtonHoldIndicator::BeginHold() {
}


