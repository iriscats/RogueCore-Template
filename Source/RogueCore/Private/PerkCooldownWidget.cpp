#include "PerkCooldownWidget.h"

UPerkCooldownWidget::UPerkCooldownWidget() : UUserWidget(FObjectInitializer::Get()) {
    this->MonitoredCharacter = NULL;
    this->MonitoredPerk = NULL;
    this->currentProgress = 1.00f;
}

void UPerkCooldownWidget::SetMonitoredPerk(AActor* Character, UPerkAsset* Perk) {
}


float UPerkCooldownWidget::GetCoolDownProgress() const {
    return 0.0f;
}

void UPerkCooldownWidget::ClearMonitoredPerk() {
}


