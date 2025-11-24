#include "PerkActivationWidgetWithItemMonitor.h"

UPerkActivationWidgetWithItemMonitor::UPerkActivationWidgetWithItemMonitor() {
    this->ItemToMonitor = NULL;
    this->ActiveItem = NULL;
}

void UPerkActivationWidgetWithItemMonitor::OnStopMonitoring_Implementation() {
}

void UPerkActivationWidgetWithItemMonitor::OnStartMonitoring_Implementation() {
}

void UPerkActivationWidgetWithItemMonitor::OnItemUnequipped(AItem* Item) {
}

void UPerkActivationWidgetWithItemMonitor::OnItemEquipped(AItem* Item) {
}

AItem* UPerkActivationWidgetWithItemMonitor::GetMonitoredItem() const {
    return NULL;
}


