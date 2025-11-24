#include "FSDHUD.h"

AFSDHUD::AFSDHUD(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
    this->DebugDisplay.AddDefaulted(1);
    this->IsVisibleFlags = 0;
    this->HUDWidget = NULL;
}

bool AFSDHUD::ToggleHUDVisibility(EHUDVisibilityReason reason) {
    return false;
}


void AFSDHUD::SetHUDWidget(UFSDMainHUDWidget* InWidget) {
}

void AFSDHUD::SetHUDVisible(bool IsVisible, EHUDVisibilityReason reason) {
}





bool AFSDHUD::IsHUDVisibleFlagSet(EHUDVisibilityReason reason) const {
    return false;
}


UFSDMainHUDWidget* AFSDHUD::GetHUDWidget() {
    return NULL;
}

bool AFSDHUD::GetHUDVisible() const {
    return false;
}

AFSDHUD* AFSDHUD::GetFSDHUD(APlayerController* InPlayerController) {
    return NULL;
}



