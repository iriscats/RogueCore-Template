#include "StreamlineSettings.h"

UStreamlineSettings::UStreamlineSettings() {
    this->bLoadDebugOverlay = false;
    this->bAllowOTAUpdate = true;
    this->NVIDIANGXApplicationId = 0;
    this->bEnableStreamlineD3D12 = true;
    this->bEnableStreamlineD3D11 = true;
    this->bEnableDLSSFGInPlayInEditorViewports = true;
    this->bUseSlSetTag = false;
}


